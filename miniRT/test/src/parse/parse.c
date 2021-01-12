/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:35:13 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/12 22:24:08 by hyeonkim         ###   ########.fr       */
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
	free(data);
}

void	get_parallel_light(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	t_color	albedo;
	char	**ori;
	t_vec	orientation;

	data = ft_split(line, ' ');
	ori = ft_split(data[0], ',');
	orientation = point(ft_atod(ori[0]), ft_atod(ori[1]), ft_atod(ori[2]));
	alb = ft_split(data[1], ',');
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(PARELLEL_LIGHT, parallel_light(orientation, albedo), 0));
	free(data);
}

void	get_ambient(char *line, t_scene *scene)
{
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
	free(data);
}

void	get_background(char *line, t_scene *scene, void *mlx)
{
	char			**data;
	t_data			*bg;
	t_texture		*t;
	double			sidelen;

	if (!(bg = (t_data *)malloc(sizeof(t_data))))
		malloc_error();
	data = ft_split(line, ' ');
	bg->img = mlx_png_file_to_image(mlx, data[0], &bg->width, &bg->height);
	sidelen = ft_atod(data[1]);
	bg->addr = mlx_get_data_addr(bg->img, &bg->bits_per_pixel,
								&bg->line_length, &bg->endian);
	t = texture_img(bg);
	scene->background = obj_new(IMAGE, cube(point(0, 0, 0), sidelen), t);
	// ft_free_arr(data);
	free(data);
}

void	get_camera(char *line, t_scene *scene)
{
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
	set_cam(cam, scene);
	obj_add_back(&scene->cam_list,
				obj_new(CAM, cam, 0));
	free(data);
}

void	get_light(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	t_color	albedo;
	char	**p;
	t_point	position;
	double	ratio;
	// double	lux;
	
	// lux = 50.0;
	data = ft_split(line, ' ');
	p = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	position = point(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]));
	ratio = ft_atod(data[1]);
	// albedo = v_multiply(albedo, lux * (ratio / 255.0));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(SPOT_LIGHT, spot_light(position, ratio, albedo), 0));
	free(data);
}

void	get_sphere(char *line, t_scene *scene)
{
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
	obj_add_back(&scene->objs, obj_new(SP, sphere(center, radius), texture(DEF, albedo)));
	free(data);
}

void	get_cylinder(char *line, t_scene *scene)
{
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
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(CY,
	cylinder(position, orientation, diameter, height), texture(DEF, albedo)));
	// printf("position : %f %f %f\n", position.x, position.y, position.z);
	// printf("orientaiton : %f %f %f\n", orientation.x,orientation.y,orientation.z);
	// printf("height : %f\n", height);
	// printf("diameter : %f\n", diameter);
	// printf("albedo : %f %f %f\n", albedo.x, albedo.y, albedo.z);
	free(data);
}

void	get_square(char *line, t_scene *scene)
{
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
	len = ft_atod(data[2]);
	orientation = vec(ft_atod(ori[0]), ft_atod(ori[1]), ft_atod(ori[2]));
	if (is_aligned(orientation) == 0)
		error_not_aligned();
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(SQ,
		square(position, orientation, len), texture(DEF, albedo)));
	free(data);
}

void	get_plane(char *line, t_scene *scene)
{
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
	orientation = vec(ft_atod(ori[0]), ft_atod(ori[1]), ft_atod(ori[2]));
	if (is_aligned(orientation) == 0)
		error_not_aligned();
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(PL,
		plane(position, orientation), texture(DEF, albedo)));
	free(data);
}

void	get_triangle(char *line, t_scene *scene)
{
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
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(TR,
		triangle(pos1, pos2, pos3), texture(DEF, albedo)));
	free(data);
}

void	get_cone(char *line, t_scene *scene)
{
	char	**data;
	char	**pos;
	t_point	position;
	char	**ori;
	t_vec	orientation;
	char	**alb;
	t_color	albedo;
	double	angle;
	double	height;

	data = ft_split(line, ' ');
	pos = ft_split(data[0], ',');
	ori = ft_split(data[1], ',');
	alb = ft_split(data[4], ',');
	position = point(ft_atod(pos[0]), ft_atod(pos[1]), ft_atod(pos[2]));
	orientation = vec(ft_atod(ori[0]), ft_atod(ori[1]), ft_atod(ori[2]));
	albedo = point(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	albedo = v_multiply(albedo, 1.0 / 255.0);
	angle = ft_atod(data[2]);
	height = ft_atod(data[3]);
	obj_add_back(&scene->objs, obj_new(CO,
		cone(position, orientation, angle, height), texture(DEF, albedo)));
	free(data);
}

void	get_cube(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	t_color	albedo;
	char	**p;
	t_point	position;
	double	len;
	
	data = ft_split(line, ' ');
	p = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	position = point(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]));
	len = ft_atod(data[1]);
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(CU, cube(position, len), texture(DEF, albedo)));
	free(data);
}

void	get_pyramid(char *line, t_scene *scene)
{
	char	**data;
	char	**alb;
	t_color	albedo;
	char	**p;
	t_point	position;
	double	len;
	
	data = ft_split(line, ' ');
	p = ft_split(data[0], ',');
	alb = ft_split(data[2], ',');
	albedo = color(ft_atod(alb[0]), ft_atod(alb[1]), ft_atod(alb[2]));
	position = point(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]));
	len = ft_atod(data[1]);
	albedo = v_multiply(albedo, 1.0 / 255.0);
	obj_add_back(&scene->objs, obj_new(PY, pyramid(position, len), texture(DEF, albedo)));
	free(data);
}