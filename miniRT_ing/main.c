/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 21:01:02 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ray.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

int			main()
{
	// Image
	double		ratio = 16.0 / 9.0;
	int			image_width = 400;
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
	
	input_elements(&origin, 0, 0, 0);
	input_elements(&horizontal, viewport_width, 0, 0);
	input_elements(&vertical, 0, viewport_height, 0);
	input_elements(&focal, 0, 0, focal_length);
	lower_left_corner = v_minus(v_minus(v_minus(origin, v_multiply(horizontal, 0.5)), v_multiply(vertical, 0.5)), focal);

	// World
	t_hittable_list		*world;
	world = NULL;
	h_lstadd_back(&world, h_lstnew(SP, sphere(point(0, 0, -1), 0.5)));
	//h_lstadd_back(&world, h_lstnew(SP, sphere(point(0, -100.5, -1), 100)));

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
			pixel_color = ray_color(r, world);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
}