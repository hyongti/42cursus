/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:35:13 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/05 11:31:38 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	get_resolution(char *line, t_scene *scene)
{
	int			width;
	int		 	height;
	char		**data;

	data = ft_split(line, ' ');
	width = ft_atoi(data[0]);
	height = ft_atoi(data[1]);
	if (width == 0 || height == 0)
	{
		write(1, "Errer\n", 6);
		exit(0);
	}
	scene->canvas.width = width;
	scene->canvas.height = height;
	scene->canvas.ratio = (double)width / (double)height;
	// printf("stored R : %d %d %f\n", scene->canvas.width, scene->canvas.height, scene->canvas.ratio);
}

void	get_ambient(char *line, t_scene *scene)
{
	// printf("A : %s\n", line);
	char		**data;
	double		strength;
	char		**alb;
	t_color		albedo;

	data = ft_split(line, ' ');
	strength = ft_atod(data[0]);
	alb = ft_split(data[1], ',');
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]),ft_atod(alb[2]));
	albedo = v_multiply(albedo, strength * 1.0 / 255.0);
	scene->global.ambient = albedo;
}

void	get_camera(char *line, t_scene *scene)
{
	// printf("c : %s\n", line);
	char		**data;
	char		**from;
	char		**dir;
	t_camera	*cam;
	t_point		lookfrom;
	t_vec		lookdir;
	double		hfov;

	data = ft_split(line, ' ');
	from = ft_split(data[0], ',');
	dir = ft_split(data[1], ',');
	lookfrom = point(ft_atod(from[0]), ft_atod(from[1]), ft_atod(from[2]));
	lookdir = vec(ft_atod(dir[0]), ft_atod(dir[1]), ft_atod(dir[2]));
	hfov = ft_atod(data[2]);
	cam = cam_init(lookfrom, lookdir, hfov);
	obj_add_back(&scene->cam_list,
				obj_new(CAM, set_cam(cam, scene)));
	// printf("%f %f %f\n", cam->dir.x, cam->dir.y, cam->dir.z);
}

void	get_light(char *line, t_scene *scene)
{
	// printf("l : %s\n", line);
	char	**data;
	char	**alb;
	t_color	albedo;
	char	**p;
	t_point	position;
	double	ratio;
	double	lux;
	
	lux = 50.0;
	data = ft_split(line, ' ');
	p = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	position = point(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]));
	ratio = ft_atod(data[1]);
	albedo = v_multiply(albedo, lux * (ratio / 255.0));
	obj_add_back(&scene->objs, obj_new(LIGHT, light(position, ratio, albedo)));
	// printf("light albedo : %f %f %f\n", albedo.x, albedo.y, albedo.z);
}

void	get_sphere(char *line, t_scene *scene)
{
	// printf("sp : %s\n", line);
	char	**data;
	char	**cen;
	t_point	center;
	double	radius;
	char	**alb;
	t_color	albedo;

	data = ft_split(line, ' ');
	cen = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	center = point(ft_atod(cen[0]), ft_atod(cen[1]), ft_atod(cen[2]));
	radius = ft_atod(data[1]);
	albedo = color(ft_atoi(alb[0]), ft_atoi(alb[1]), ft_atoi(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	// printf("%f %f %f\n", albedo.x, albedo.y, albedo.z);
	// printf("%f %f %f\n", center.x, center.y, center.z);
	obj_add_back(&scene->objs, obj_new(SP, sphere(center, radius, albedo)));
}

void	get_cylinder(char *line, t_scene *scene)
{
	// printf("cy : %s\n", line);
	char	**data;
	char	**pos;
	t_point	position;
	char	**ori;
	t_vec	orientation;
	double	diameter;
	double	height;
	char	**alb;
	t_color	albedo;

	data = ft_split(line, ' ');
	pos = ft_split(data[0], ',');
	ori = ft_split(data[1], ',');
	alb = ft_split(data[4], ',');
	position = point(ft_atod(pos[0]), ft_atod(pos[1]), ft_atod(pos[2]));
	orientation = point(ft_atod(ori[0]), ft_atod(ori[1]), ft_atod(ori[2]));
	diameter = ft_atod(data[2]);
	height = ft_atod(data[3]);
	// printf("%f\n", height);
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(CY,
	cylinder(position, orientation, diameter, height, albedo)));
}

void	get_square(char *line, t_scene *scene)
{
	// printf("sq : %s\n", line);
	char	**data;
	char	**pos;
	t_point	position;
	double	len;
	char	**ori;
	t_vec	orientation;
	char	**alb;
	t_color	albedo;

	data = ft_split(line, ' ');
	pos = ft_split(data[0], ',');
	ori = ft_split(data[1], ',');
	alb = ft_split(data[3], ',');
	position = point(ft_atod(pos[0]), ft_atod(pos[1]), ft_atod(pos[2]));
	position = v_plus(position, vec(1e-6, 1e-6, 1e-6));
	len = ft_atod(data[2]);
	orientation = vec(ft_atod(ori[0]), ft_atod(ori[1]), ft_atod(ori[2]));
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	// printf("%f\n", len);
	obj_add_back(&scene->objs, obj_new(SQ,
		square(position, orientation, len, albedo)));
	// printf("%f %f %f\n", position.x, position.y, position.z);
	// printf("%f %f %f\n", orientation.x, orientation.y, orientation.z);
	// printf("%f\n", len);
}

void	get_plane(char *line, t_scene *scene)
{
	// printf("pl : %s\n", line);
	char	**data;
	char	**pos;
	t_point	position;
	char	**ori;
	t_vec	orientation;
	char	**alb;
	t_color	albedo;

	data = ft_split(line, ' ');
	pos = ft_split(data[0], ',');
	ori = ft_split(data[1], ',');
	alb = ft_split(data[2], ',');
	position = point(ft_atod(pos[0]), ft_atod(pos[1]), ft_atod(pos[2]));
	// position = v_minus(position, point(1e-4, 1e-4, 1e-4));
	orientation = vec(ft_atod(ori[0]), ft_atod(ori[1]), ft_atod(ori[2]));
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	// printf("%f %f %f\n", orientation.x, orientation.y, orientation.z);
	obj_add_back(&scene->objs, obj_new(PL,
		plane(position, orientation, albedo)));
}

void	get_triangle(char *line, t_scene *scene)
{
	// printf("tr : %s\n", line);
	char	**data;
	char	**p1;
	t_point	pos1;
	char	**p2;
	t_point	pos2;
	char	**p3;
	t_point pos3;
	char	**alb;
	t_color	albedo;

	data = ft_split(line, ' ');
	p1 = ft_split(data[0], ',');
	p2 = ft_split(data[1], ',');
	p3 = ft_split(data[2], ',');
	alb = ft_split(data[3], ',');
	pos1 = point(ft_atod(p1[0]), ft_atod(p1[1]), ft_atod(p1[2]));
	pos2 = point(ft_atod(p2[0]), ft_atod(p2[1]), ft_atod(p2[2]));
	pos3 = point(ft_atod(p3[0]), ft_atod(p3[1]), ft_atod(p3[2]));
	// position = v_minus(position, point(1e-4, 1e-4, 1e-4));
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	// printf("%f %f %f\n", orientation.x, orientation.y, orientation.z);
	obj_add_back(&scene->objs, obj_new(TR,
		triangle(pos1, pos2, pos3, albedo)));
	// printf("p1.x : %f, p2.x : %f, p3.x : %f\n", pos1.x, pos2.x, pos3.x);
}