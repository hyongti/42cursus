/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/06 19:21:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ray.h"
#include "color.h"
#include "hittable.h"
#include "random.h"
#include "camera.h"

int			main()
{
	// Image
	double		ratio = 16.0 / 9.0;
	int			image_width = 400;
	int			image_height = (int)(image_width / ratio);
	int			samples_per_pixel = 100;
	int			s;

	// Camera
	t_camera	cam;
	set_camera(&cam, ratio);
	
	// World
	t_hittable_list		*world;
	t_material	material_ground;
	t_material	material_center;
	t_material	material_left;
	t_material	material_right;

	material_ground = make_material(LAMBERTIAN, color(0.8, 0.8, 0.0));
	material_center = make_material(LAMBERTIAN, color(0.7, 0.3, 0.3));
	material_left = make_material(METAL, color(0.8, 0.8, 0.8));
	material_right = make_material(METAL, color(0.8, 0.6, 0.2));

	world = NULL;
	h_lstadd_back(&world, h_lstnew(SP, sphere(point(-1, -100.5, -1), 100, material_ground)));
	h_lstadd_back(&world, h_lstnew(SP, sphere(point(0, 0, -1), 0.5, material_center)));
	h_lstadd_back(&world, h_lstnew(SP, sphere(point(-1, 0, -1), 0.5, material_left)));
	h_lstadd_back(&world, h_lstnew(SP, sphere(point(1, 0, -1), 0.5, material_right)));

	//Render
	int			depth = 50;
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
			pixel_color = color(0, 0, 0);
			s = 0;
			while (s < samples_per_pixel)
			{
				u = ((double)i + random_double()) / (image_width - 1);
				v = ((double)j + random_double()) / (image_height - 1);
				r = get_ray(cam, u, v);
				pixel_color = v_plus(pixel_color, ray_color(r, world, depth));
				++s;
			}
			write_color(pixel_color, samples_per_pixel);
			++i;
		}
		--j;
	}
}