/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:48:46 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/05 20:59:45 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "hit.h"
#include "mlx.h"
#include "control.h"
#include <pthread.h>

static void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render(t_scene *scene, t_data *img)
{
	// Render
	int			i;
	int			j = scene->canvas.height - 1;
	double		u;
	double		v;
	t_ray		r;
	t_color		pixel_color;

	// scene->cam_onair = scene->cam_list->object;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			r = ray(scene->cam_onair->origin, v_normalize(v_minus(v_plus(v_plus(scene->cam_onair->leftbottom, 
					v_multiply(scene->cam_onair->horizontal, u)), v_multiply(scene->cam_onair->vertical, v)), scene->cam_onair->origin)));
			pixel_color = ray_color(r, scene->objs);
			my_mlx_pixel_put(img, i, scene->canvas.height - 1 - j, color_to_int(pixel_color));
			++i;
		}
		--j;
	}
}

void	render_preview(t_scene *scene, t_data *img, int light_on)
{
	// Render
	int			i;
	int			j = scene->canvas.height - 1;
	double		u;
	double		v;
	t_ray		r;
	t_color		pixel_color;

	// scene->cam_onair = scene->cam_list->object;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			r = ray(scene->cam_onair->origin, v_normalize(v_minus(v_plus(v_plus(scene->cam_onair->leftbottom, 
					v_multiply(scene->cam_onair->horizontal, u)), v_multiply(scene->cam_onair->vertical, v)), scene->cam_onair->origin)));
			if (light_on == LIGHT_OFF)		
				pixel_color = ray_color_preview(r, scene->objs);
			else if (light_on == LIGHT_ON)
				pixel_color = ray_color(r, scene->objs);
			my_mlx_pixel_put(img, i, scene->canvas.height - 1 - j, color_to_int(pixel_color));
			++i;
		}
		--j;
	}
}