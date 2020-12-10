/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/09 23:23:30 by hyongti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_utils.h"
#include "ray.h"
#include "color.h"
#include "hit.h"
#include "objects.h"
#include "make_object.h"

int			main()
{
	// Image
	double		ratio = 16.0 / 9.0;
	int			image_width = 1920;
	int			image_height = (int)(image_width / ratio);

	// Camera
	double		viewport_height = 2.0;
	double		viewport_width = ratio * viewport_height;
	double		focal_length = 1.0;

	t_point		origin;
	t_vec		horizontal;
	t_vec		vertical;
	t_vec		focal;
	t_vec		lower_left_corner;
	
	origin = point(0, 0, 0);
	horizontal = vec(viewport_width, 0, 0);
	vertical = vec(0, viewport_height, 0);
	focal = vec(0, 0, focal_length);
	lower_left_corner = v_minus(v_minus(v_minus(origin, v_multiply(horizontal, 0.5)), v_multiply(vertical, 0.5)), focal);

	// World
	t_objects	*objects;
	objects = NULL;
	// objects_add_back(&objects, objects_new(SP, sphere(point(0, 1, -5), 1, color(1, 1, 1))));
	
	// light = sphere(point(0, 5, -7), 0.1, color(1, 1, 1));
	objects_add_back(&objects, objects_new(SP, sphere(point(0, 0, -2), 0.5, color(1, 0, 0))));
	objects_add_back(&objects, objects_new(LIGHT, light(point(3, 3, 0), color(0.5, 1, 1))));
	objects_add_back(&objects, objects_new(LIGHT, light(point(0, 3, 0), color(0.5, 1, 1))));
	// objects_add_back(&objects, objects_new(LIGHT, light(point(5, -5, -7), color(1, 1, 1))));
	// objects_add_back(&objects, objects_new(LIGHT, light(point(-5, 5, -7), color(1, 1, 1))));
	// objects_add_back(&objects, objects_new(LIGHT, light(point(-5, -5, -7), color(1, 1, 1))));
	// objects_add_back(&objects, objects_new(SP, sphere(point(7, -1, -15), 3.0, color(0, 1, 0))));
	// objects_add_back(&objects, objects_new(PL, sphere(point(7, -1, -15), 3.0, color(0, 1, 0))));
	objects_add_back(&objects, objects_new(TR, triangle(point(-5, -3, -10), point(10, -3, -20), point(3, 5, -15), color(0.2, 0.2, 0.2))));	
	//Render
	int			i;
	int			j = image_height - 1;
	double		u;
	double		v;
	t_ray		r;
	t_color		pixel_color;

	printf("P3\n%d %d\n255\n", image_width, image_height);
	while (j >= 0)
	{
		i = 0;
		while (i < image_width)
		{
			u = (double)i / (image_width - 1);
			v = (double)j / (image_height - 1);
			r = ray(origin, v_minus(v_plus(v_plus(lower_left_corner, 
					v_multiply(horizontal, u)), v_multiply(vertical, v)), origin));
			pixel_color = ray_color(r, objects);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
}