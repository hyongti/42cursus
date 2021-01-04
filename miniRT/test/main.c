/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/02 18:47:02 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_utils.h"
#include "ray.h"
#include "color.h"
#include "hit.h"
#include "objects.h"
#include "scene.h"
#include "make_object.h"
#include "parse.h"

int		main(int argc, char *argv[])
{
	t_scene		*scene;

	if (argc == 2)
	{
		scene = read_rt(argv[1]);
		
		// // Image
		// int			scene->canvas.width = 400;
		// int			scene->canvas.height = 225;
		// double		ratio = (double)scene->canvas.width / (double)scene->canvas.height;

		// // Camera
		// double		viewport_height = 2.0;
		// double		viewport_width = ratio * viewport_height;
		// double		focal_length = 1.0;

		// t_point		origin;
		// t_vec		horizontal;
		// t_vec		vertical;
		// t_vec		focal;
		// t_vec		lower_left_corner;

		// origin = point(0, 0, 0);
		// horizontal = vec(viewport_width, 0, 0);
		// vertical = vec(0, viewport_height, 0);
		// focal = vec(0, 0, focal_length);
		// lower_left_corner = v_minus(v_minus(v_minus(origin, v_multiply(horizontal, 0.5)), v_multiply(vertical, 0.5)), focal);

		// World
		// t_objects	*objects;
		// objects = 0;

			// // obj_add_back(&objects, obj_new(SP, sphere(point(0, 0, -5), 0.5, color(0.5, 0.3, 0.3))));
			// // obj_add_back(&objects, obj_new(SP, sphere(point(2, 2, -5), 1, color(1.0 , 0, 1.0))));
			// // obj_add_back(&objects, obj_new(LIGHT, light(point(2, 3, -5), color(0.6, 0.6, 0.6))));
			// obj_add_back(&objects, obj_new(SQ, square(point(-1, 0.0001, -3), vec(0, 0, 1), 1.0, color(0.0, 0.0, 1.0))));
			// obj_add_back(&objects, obj_new(TR, triangle(point(-1.6, 0.5, -3), point(-1, 1.5, -3), point(-0.4, 0.5, -3), color(0, 0, 1.0))));
			// obj_add_back(&objects, obj_new(LIGHT, light(point(3, 0, 0), color(10.0, 10.0, 10.0))));
			// // obj_add_back(&objects, obj_new(LIGHT, light(point(0, 3, 0), color(20.0, 20.0, 20.0))));
			// obj_add_back(&objects, obj_new(LIGHT, light(point(-3, 0, 0), color(10, 10, 10))));
			// // obj_add_back(&objects, obj_new(LIGHT, light(point(-5, 5, -7), color(1, 1, 1))));
			// // obj_add_back(&objects, obj_new(LIGHT, light(point(-5, -5, -7), color(1, 1, 1))));
			// obj_add_back(&objects, obj_new(SP, sphere(point(3, 2.356, -5), 0.5, color(0, 1, 0))));
			// // obj_add_back(&objects, obj_new(PL, sphere(point(7, -1, -15), 3.0, color(0, 1, 0))));
			// obj_add_back(&objects, obj_new(CY, cylinder(point(3, -0.5, -5), vec(0, 1, 0), 0.5, 2.5, color(0, 1.0, 0))));
			// // obj_add_back(&objects, obj_new(CO, cone(point(3, 1.5, -3), 10, vec(0, -1, 0), 1.5, color(1.0 , 0, 0.5))));
			// // obj_add_back(&objects, obj_new(CY, cylinder(point(0, -0.5, -7), vec(0, 1, 0), color(0, 1.0, 0), 0.5, 0.5)));
			// // obj_add_back(&objects, obj_new(PL, plane(point(0, 0, -10), vec(0, 0, 1), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));
			// // obj_add_back(&objects, obj_new(PL, plane(point(7, 0, 0), vec(-1, 0, 0), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));
			// // obj_add_back(&objects, obj_new(PL, plane(point(-7, 0, 0), vec(1, 0, 0), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));
			// obj_add_back(&objects, obj_new(PL, plane(point(0, -0.5, 0), vec(0, -1, 0), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));

		// Render
		int			i;
		int			j = scene->canvas.height - 1;
		double		u;
		double		v;
		t_ray		r;
		t_color		pixel_color;
		scene->on_air = scene->cam_list->object;
		// printf("%f %f %f\n", scene->on_air->leftbottom.x, scene->on_air->leftbottom.y, scene->on_air->leftbottom.z);
		printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
		while (j >= 0)
		{
			i = 0;
			while (i < scene->canvas.width)
			{
				u = (double)i / (scene->canvas.width - 1);
				v = (double)j / (scene->canvas.height - 1);
				r = ray(scene->on_air->origin, v_normalize(v_minus(v_plus(v_plus(scene->on_air->leftbottom, 
						v_multiply(scene->on_air->horizontal, u)), v_multiply(scene->on_air->vertical, v)), scene->on_air->origin)));
				// printf("%f %f %f\n", r.dir.x, r.dir.y, r.dir.z);
				pixel_color = ray_color(r, scene->objs);
				// printf("%f %f %f\n", pixel_color.x, pixel_color.y, pixel_color.z);
				write_color(pixel_color);
				++i;
			}
			--j;
		}
		free(scene);
	}
}

// int			main()
// {
// 	// Image
// 	int			scene->canvas.width = 400;
// 	int			scene->canvas.height = 225;
// 	double		ratio = (double)scene->canvas.width / (double)scene->canvas.height;

// 	// Camera
// 	double		viewport_height = 2.0;
// 	double		viewport_width = ratio * viewport_height;
// 	double		focal_length = 1.0;

// 	t_point		origin;
// 	t_vec		horizontal;
// 	t_vec		vertical;
// 	t_vec		focal;
// 	t_vec		lower_left_corner;
	
// 	origin = point(0, 0, 0);
// 	horizontal = vec(viewport_width, 0, 0);
// 	vertical = vec(0, viewport_height, 0);
// 	focal = vec(0, 0, focal_length);
// 	lower_left_corner = v_minus(v_minus(v_minus(origin, v_multiply(horizontal, 0.5)), v_multiply(vertical, 0.5)), focal);

// 	// World
// 	t_objects	*objects;
// 	objects = 0;
	
// 	// obj_add_back(&objects, obj_new(SP, sphere(point(0, 0, -5), 0.5, color(0.5, 0.3, 0.3))));
// 	// obj_add_back(&objects, obj_new(SP, sphere(point(2, 2, -5), 1, color(1.0 , 0, 1.0))));
// 	// obj_add_back(&objects, obj_new(LIGHT, light(point(2, 3, -5), color(0.6, 0.6, 0.6))));
// 	obj_add_back(&objects, obj_new(SQ, square(point(-1, 0.0001, -3), vec(0, 0, 1), 1.0, color(0.0, 0.0, 1.0))));
// 	obj_add_back(&objects, obj_new(TR, triangle(point(-1.6, 0.5, -3), point(-1, 1.5, -3), point(-0.4, 0.5, -3), color(0, 0, 1.0))));
// 	obj_add_back(&objects, obj_new(LIGHT, light(point(3, 0, 0), color(10.0, 10.0, 10.0))));
// 	// obj_add_back(&objects, obj_new(LIGHT, light(point(0, 3, 0), color(20.0, 20.0, 20.0))));
// 	obj_add_back(&objects, obj_new(LIGHT, light(point(-3, 0, 0), color(10, 10, 10))));
// 	// obj_add_back(&objects, obj_new(LIGHT, light(point(-5, 5, -7), color(1, 1, 1))));
// 	// obj_add_back(&objects, obj_new(LIGHT, light(point(-5, -5, -7), color(1, 1, 1))));
// 	obj_add_back(&objects, obj_new(SP, sphere(point(3, 2.356, -5), 0.5, color(0, 1, 0))));
// 	// obj_add_back(&objects, obj_new(PL, sphere(point(7, -1, -15), 3.0, color(0, 1, 0))));
// 	obj_add_back(&objects, obj_new(CY, cylinder(point(3, -0.5, -5), vec(0, 1, 0), 0.5, 2.5, color(0, 1.0, 0))));
// 	// obj_add_back(&objects, obj_new(CO, cone(point(3, 1.5, -3), 10, vec(0, -1, 0), 1.5, color(1.0 , 0, 0.5))));
// 	// obj_add_back(&objects, obj_new(CY, cylinder(point(0, -0.5, -7), vec(0, 1, 0), color(0, 1.0, 0), 0.5, 0.5)));
// 	// obj_add_back(&objects, obj_new(PL, plane(point(0, 0, -10), vec(0, 0, 1), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));
// 	// obj_add_back(&objects, obj_new(PL, plane(point(7, 0, 0), vec(-1, 0, 0), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));
// 	// obj_add_back(&objects, obj_new(PL, plane(point(-7, 0, 0), vec(1, 0, 0), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));
// 	obj_add_back(&objects, obj_new(PL, plane(point(0, -0.5, 0), vec(0, -1, 0), color(222.0 / 255.0, 158.0 / 255.0, 80.0 / 255.0))));

// 	//Render
// 	int			i;
// 	int			j = scene->canvas.height - 1;
// 	double		u;
// 	double		v;
// 	t_ray		r;
// 	t_color		pixel_color;

// 	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
// 	while (j >= 0)
// 	{
// 		i = 0;
// 		while (i < scene->canvas.width)
// 		{
// 			u = (double)i / (scene->canvas.width - 1);
// 			v = (double)j / (scene->canvas.height - 1);
// 			r = ray(origin, v_normalize(v_minus(v_plus(v_plus(lower_left_corner, 
// 					v_multiply(horizontal, u)), v_multiply(vertical, v)), origin)));
// 			pixel_color = ray_color(r, objects);
// 			write_color(pixel_color);
// 			++i;
// 		}
// 		--j;
// 	}
// }