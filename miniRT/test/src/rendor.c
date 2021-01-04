/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:48:46 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/04 15:54:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "hit.h"
#include "mlx.h"

static void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	render(t_scene *scene, t_data img)
{
	// Render
	int			i;
	int			j = scene->canvas.height - 1;
	double		u;
	double		v;
	t_ray		r;
	t_color		pixel_color;
	scene->on_air = scene->cam_list->object;
	// printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			r = ray(scene->on_air->origin, v_normalize(v_minus(v_plus(v_plus(scene->on_air->leftbottom, 
					v_multiply(scene->on_air->horizontal, u)), v_multiply(scene->on_air->vertical, v)), scene->on_air->origin)));
			pixel_color = ray_color(r, scene->objs);
			my_mlx_pixel_put(&img, i, scene->canvas.height - 1 - j, color_to_int(pixel_color));
			++i;
		}
		--j;
	}
}