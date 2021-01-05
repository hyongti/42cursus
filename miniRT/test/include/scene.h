/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 19:16:18 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/05 21:03:26 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include "objects.h"
#include "light.h"
#include "color.h"
#include "mlx.h"

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_canvas
{
	int			width;
	int			height;
	double		ratio;
}				t_canvas;

typedef struct	s_camera
{
	double		hfov;
	t_point		origin;
	t_point		dir;
	t_vec		horizontal;
	t_vec		vertical;
	t_vec		focal;
	t_point		leftbottom;
}				t_camera;

typedef struct	s_global
{
	t_color		ambient;
	int			samples_per_pixel;
}				t_global;

typedef struct	s_scene
{
	t_global	global;
	t_canvas	canvas;
	t_objects	*cam_list;
	t_camera	*cam_onair;
	t_objects	*objs;
	t_data		*img;
}				t_scene;

void		scene_init(t_scene *scene);
t_camera	*cam_init(t_point lookfrom, t_vec lookdir, double hfov);
t_camera	*set_cam(t_camera *camera, t_scene *scene);
void		render(t_scene *scene, t_data *img);
void		render_preview(t_scene *scene, t_data *img, int light_on);

# endif