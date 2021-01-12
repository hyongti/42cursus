/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 02:44:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/12 21:07:41 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int		check_shadow(t_ray *ray, t_objects *objects)
{
	t_hit_record	rec;
	int				hit_anything;

	rec.t_min = 0.001;
	rec.t_max = v_len(ray->dir);
	ray->dir = v_normalize(ray->dir);
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(ray, objects, &rec))
			hit_anything = TRUE;
		objects = objects->next;
	}
	return (hit_anything);
}

t_color	phong_color_spot(t_ray *r, t_spot_light *light, t_hit_record *rec, t_objects *objects_for_check)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vec		light_dir;
	t_vec		view_dir;
	t_vec		reflect_dir;
	t_vec		unit_norm;
	t_ray		to_light_ray;
	t_color		albedo;
	double		lux = 50;
	double		ka;
	double		kd;
	double		ks;
	double		ksn;
	double		spec;
	double		distance_attenuation;

	unit_norm = v_normalize(rec->normal);
	view_dir = v_multiply(r->dir, -1);
	light_dir = v_minus(light->p, rec->p);
	to_light_ray = ray(v_plus(rec->p, v_multiply(rec->normal, 1e-4)), light_dir);
	if (check_shadow(&to_light_ray, objects_for_check))
		return (color(0, 0, 0));
	light_dir = v_normalize(light_dir);
	reflect_dir = reflect(v_multiply(light_dir, -1), unit_norm);
	ka = 0.1; // ambient strength;
	kd = fmax(v_dot(unit_norm, light_dir), 0.0);// diffuse strength;
	ks = 0.5; // specular strength;
	ksn = 256;
	albedo = v_multiply(light->color, lux * light->brightness);
	ambient = v_multiply(albedo, ka);
	diffuse = v_multiply(albedo, kd);

	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = v_multiply(v_multiply(albedo, kd), spec);

	distance_attenuation = 1.0 / v_len_squared(v_minus(light->p, rec->p));

	return (v_multiply(v_plus(v_plus(ambient, diffuse), specular), distance_attenuation));
}
