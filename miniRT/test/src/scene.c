/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:46:06 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/02 01:18:09 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void		scene_init(t_scene *scene)
{
	scene->objs = NULL;
	scene->cam_list = NULL;
	scene->on_air = NULL;
}

t_camera	*cam_init(t_point lookfrom, t_vec lookdir, double hfov)
{
	t_camera	*cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		exit (0);
	cam->origin = lookfrom;
	cam->dir = lookdir;
	cam->hfov = hfov;
	return (cam);
}

t_camera	*set_cam(t_camera *cam, t_scene *scene)
{
	double		theta;
	double		half_width;
	double		viewport_height;
	double		viewport_width;
	t_vec		u;
	t_vec		v;
	t_vec		w;
	t_vec		vup;
	t_vec		lookat;

	lookat = v_plus(cam->origin, cam->dir);
	vup = vec(0, 1, 0);
	theta = deg_to_rad(cam->hfov);
	half_width = tan(theta / 2.0);
	viewport_width = 2.0 * half_width;
	viewport_height = viewport_width / scene->canvas.ratio;
	w = v_normalize(v_multiply(cam->dir, -1));
	u = v_normalize(v_cross(vup, w));
	v = v_cross(w, u);
	cam->horizontal = v_multiply(u, viewport_width);
	cam->vertical = v_multiply(v, viewport_height);
	cam->leftbottom = v_minus(v_minus(v_minus(cam->origin, v_multiply(cam->horizontal, 0.5)), v_multiply(cam->vertical, 0.5)), w);
	return (cam);
}
// t_image			image(int width, int height)
// {
// 	t_image		image;

// 	image.width = width;
// 	image.height = height;
// 	image.ratio = (double)width / (double)height;
// 	return (image);
// }

// t_cam			cam_set
// {
// 	t_cam		cam;

// 	double		viewport_height = 2.0;
// 	double		viewport_width = image.ratio * viewport_height;
// 	double		focal_length = 1.0;


// }