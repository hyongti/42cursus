/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:20:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/18 01:29:35 by hyongti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

int			hit_objects(t_ray r, t_objects *objects, t_hit_record *rec)
{
	int		hit_result;

	hit_result = FALSE;
	if (objects->type == SP)
		hit_result = hit_sphere(r, (t_sphere *)objects->object, rec);
	else if (objects->type == LIGHT)
		hit_result = FALSE;
	else if (objects->type == TR)
		hit_result = hit_triangle(r, (t_triangle *)objects->object, rec);
	else if (objects->type == CY)
	{
		// printf("test test test test test test\n");
		hit_result = hit_cylinder(r, (t_cylinder *)objects->object, rec);
	}
	else if (objects->type == SQ)
	{
		hit_result = hit_square(r, (t_square *)objects->object, rec);
		// printf("test\n");
	}
	else if (objects->type == PL)
		hit_result = hit_plane(r, (t_plane *)objects->object, rec);
	return (hit_result);
}

int			hit(t_ray r, t_objects *objects, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	int				hit_anything;

	tmp_rec = *rec;
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(r, objects, &tmp_rec))
		{
			hit_anything = TRUE;
			tmp_rec.t_max = tmp_rec.t;
			*rec = tmp_rec;
			// if (objects->type == TR)
				// printf("TRIANGLE!!!\n");
		}
		objects = objects->next;
	}
	return (hit_anything);
}

static int		check_shadow(t_ray light_dir_ray, t_objects *objects)
{
	t_hit_record	rec;
	int				hit_anything;

	// tmp_rec.t_min = rec->t_min;
	// tmp_rec.t_max = rec->t_max;
	rec.t_min = 0.001;
	rec.t_max = v_len(light_dir_ray.dir);
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(light_dir_ray, objects, &rec))
		{
			// printf("%d\n", objects->type);
			hit_anything = TRUE;
			// if (objects->type == TR)
				// printf("SHADOW OF TRIANGLE!!!\n");
			// if (objects->type == SP)
				// printf("SHADOW OF SPHERE!!!\n");
			// if (objects->type == CY)
				// printf("SHADOW OF CYLINDER!!!\n");
		}
		objects = objects->next;
	}
	return (hit_anything);
}

static t_vec	reflect(t_vec v, t_vec n)
{
	//v - 2 * dot(v, n) * n;
	return (v_minus(v, v_multiply(n ,v_dot(v, n) * 2)));
}

static t_color	phong_color_cal(t_ray r, t_light *light, t_hit_record *rec, t_objects *objects_for_check)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vec		light_dir;
	t_vec		view_dir;
	t_vec		reflect_dir;
	t_vec		unit_norm;

	double		ka;
	double		kd;
	double		ks;
	double		ksn;
	double		spec;
	unit_norm = v_normalize(rec->normal);
	view_dir = v_multiply(r.dir, -1);
	// printf("%f %f %f\n", r.dir.x, r.dir.y, r.dir.z);
	light_dir = v_normalize(v_minus(light->point, rec->p));
	// printf("%f %f %f\n", light_dir.x, light_dir.y, light_dir.z);
	reflect_dir = reflect(v_multiply(light_dir, -1), unit_norm);
	if (check_shadow(ray(v_plus(rec->p, v_multiply(rec->normal, 0.0001)), light_dir), objects_for_check))
		return (color(0, 0, 0));
	ka = 0.1; // ambient strength;
	kd = fmax(v_dot(unit_norm, light_dir), 0.0);// diffuse strength;
	ks = 0.5; // specular strength;
	ksn = 256;
	ambient = v_multiply(light->color, ka);
	diffuse = v_multiply(light->color, kd);
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = v_multiply(v_multiply(light->color, kd), spec);

	return (v_plus(v_plus(ambient, diffuse), specular));
}

static t_color	phong_color(t_ray r, t_objects *objects, t_hit_record *rec)
{
	t_color		light_color;
	t_objects	*obj_for_check;

	light_color = color(0, 0, 0);
	obj_for_check = objects;
	while (objects)
	{
		if (objects->type == LIGHT)
			light_color = v_plus(light_color, phong_color_cal(r, objects->object, rec, obj_for_check));
		objects = objects->next;
	}
	light_color = v_multiply_2(light_color, rec->color);
	light_color.x = fmin(light_color.x, 1);
	light_color.y = fmin(light_color.y, 1);
	light_color.z = fmin(light_color.z, 1);

	return (light_color);
}

t_color		ray_color(t_ray r, t_objects *objects)
{
	t_hit_record	rec;
	double			t;
	t_vec			unit_direction;
	t_vec			normal;

	rec.t_max = INFINITY;
	rec.t_min = 0.0001;
	// printf("%f %f %f\n", r.dir.x, r.dir.y, r.dir.z);
	if (hit(r, objects, &rec))
	{
		if (objects->type == LIGHT)
			return (((t_light *)(objects->object))->color);
		return (phong_color(r, objects, &rec));
	}
	unit_direction = v_normalize(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (v_plus(v_multiply(color(1, 1, 1), 1.0 - t), v_multiply(color(0.5, 0.7, 1.0), t)));
}