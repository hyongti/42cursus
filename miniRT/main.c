/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:36:36 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/01 20:22:12 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "color.h"
#include "hit.h"
#include "viewport.h"

static void			print_ray(t_vec dir, t_vec origin)
{
	t_vec			color_1;
	t_vec			color_2;
	t_vec			color_3;
	t_vec			norm_ray;
	t_sphere		sphere;
	t_vec			normal;
	t_vec			ray;
	t_record		*rec;
	double			t;
	double			t2;

	if (!(rec = (t_record *)malloc(sizeof(t_record))))
		return ;
	ray = v_plus(origin, dir);
	input_elements(&color_1, 1.0, 1.0, 1.0);
	input_elements(&color_2, 0.5, 0.7, 1.0);
	input_elements(&sphere.center, 0, 0, -1);
	sphere.radius = 0.5;
	norm_ray = v_normalize(ray);
	t = hit_sphere(origin, dir, sphere, rec);
	if (t > 0.0)
		write_color(v_multiply(v_plus(rec->normal, color_1), 0.5));	
	else
	{
		t = 0.5 * (norm_ray.y + 1.0);
		write_color(v_plus(v_multiply(color_1, (1.0 - t)), v_multiply(color_2, t)));
	}
}

int					main()
{
	t_vec			origin;
	t_ray			base;
	t_vec			lower_left_corner;
	t_vec			dir;
	t_pixels		pixels;
	t_viewport		viewport;
	t_idx			idx;;

	set_pixels(&pixels, 16.0 / 9.0 , 400);
	// set_viewport(&viewport, pixels, 2.0, 1.0);
	viewport.height = 2.0;
	viewport.width = pixels.ratio * viewport.height;
	viewport.focal = 1.0;
	input_elements(&origin, 0, 0, 0);
	set_base_ray(&base, viewport);
	lower_left_corner = get_llc(origin, base);
	printf("P3\n%d %d\n255\n", pixels.width, pixels.height);
	idx.j = pixels.height - 1;
	while (idx.j >= 0)
	{
		idx.i = 0;
		while (idx.i < pixels.width)
		{
			idx.u = (double)idx.i / (double)(pixels.width - 1);
			idx.v = (double)idx.j / (double)(pixels.height - 1);
			dir = get_ray(lower_left_corner, base, idx, origin);
			print_ray(dir, origin);
			idx.i++;
		}
		idx.j--;
	}
}