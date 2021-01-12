/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_parallel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 02:45:36 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/11 02:46:16 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int		check_parellel_shadow(t_ray *r, t_objects *objects)
{
	t_hit_record	rec;
	int				hit_anything;

	rec.t_min = 0.001;
	rec.t_max = v_len(r->dir);
	r->dir = v_normalize(r->dir);
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(r, objects, &rec))
			hit_anything = TRUE;
		objects = objects->next;
	}
	return (hit_anything);
}

t_color	phong_color_parallel(t_ray *r, t_parallel_light *pl, t_hit_record *rec, t_objects *objects_for_check)
{
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_vec		light_dir;
	t_vec		view_dir;
	t_vec		reflect_dir;
	t_vec		unit_norm;
	t_ray		to_light_ray;
	double		ka;
	double		kd;
	double		ks;
	double		ksn;
	double		spec;

	unit_norm = v_normalize(rec->normal);
	view_dir = v_multiply(r->dir, -1);
	light_dir = v_multiply(pl->dir, -1);
	to_light_ray = ray(v_plus(rec->p, v_multiply(rec->normal, 1e-4)), light_dir);
	if (check_parellel_shadow(&to_light_ray, objects_for_check))
		return (color(0, 0, 0));
	light_dir = v_normalize(light_dir);
	reflect_dir = reflect(v_multiply(light_dir, -1), unit_norm);
	ka = 0.1; // ambient strength;
	kd = fmax(v_dot(unit_norm, light_dir), 0.0);// diffuse strength;
	ks = 0.5; // specular strength;
	ksn = 256;
	ambient = v_multiply(pl->albedo, ka);
	diffuse = v_multiply(pl->albedo, kd);
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = v_multiply(v_multiply(pl->albedo, kd), spec);
	return (v_plus(v_plus(ambient, diffuse), specular));
}