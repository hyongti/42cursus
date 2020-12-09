/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:20:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/08 21:21:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

void		set_face_normal(t_ray r, t_hit_record *rec)
{
	if (v_dot(r.dir, rec->normal) < 0)
		rec->front_face = TRUE;
	else
	{
		rec->normal = v_multiply(rec->normal, -1);
		rec->front_face = FALSE;
	}
}

double		hit_sphere(t_ray r, t_sphere *sphere, t_hit_record *rec)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;

	oc = v_minus(r.origin, sphere->center);
	a = v_dot(r.dir, r.dir);
	b = v_dot(oc, r.dir);
	c = v_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (FALSE);
	else
	{
//		printf("test test test test test test\n");
		sqrtd = sqrt(discriminant);
		root = (-b - sqrtd) / a;
		if (root < rec->t_min || root > rec->t_max)
		{
//			printf("test test test test test test\n");
			root = (-b + sqrtd) / a;
			if (root < rec->t_min || root > rec->t_max)
				return (FALSE);
		}
		rec->t = root;
		rec->p = at(rec->t, r);
		rec->normal = v_multiply(v_minus(rec->p, sphere->center), 1 / sphere->radius);
		rec->sphere = *sphere;
		//printf("%f\n", v_dot(r.dir, rec->normal));
		set_face_normal(r, rec);
		return (TRUE);
	}
}

int			hit_objects(t_ray r, t_objects *objects, t_hit_record *rec)
{
	int		hit;

	hit = FALSE;
	if (objects->type == SP)
		hit = hit_sphere(r, (t_sphere *)objects->object, rec);
	return (hit);
}

int			hit(t_ray r, t_objects *objects, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	int				hit_anything;

	tmp_rec.t_min = rec->t_min;
	tmp_rec.t_max = rec->t_max;
	hit_anything = FALSE;
	while (objects)
	{
		if (hit_objects(r, objects, &tmp_rec))
		{
			hit_anything = TRUE;
			tmp_rec.t_max = tmp_rec.t;
			*rec = tmp_rec;
		}
		objects = objects->next;
	}
	return (hit_anything);
}

static t_color	phong_color(t_ray r, t_sphere *sphere, t_sphere *light, t_hit_record *rec)
{
	t_vec			sphere_to_light;
	t_vec			reflected;
	double			ambient_strength;
	double			phong;
	double			diff;
	double			spec;
	double			specular_strength;
	// printf("%f %f %f\n", rec.sphere.center.x, rec.sphere.center.y, rec.sphere.center.z);

	// ambient;
	ambient_strength = 0.1;
	t_color ambient = v_multiply(light->color, ambient_strength);

	// diffuse
	sphere_to_light = v_normalize(v_minus(light->center, rec->sphere.center));
	diff = v_dot(sphere_to_light, rec->normal);
	diff = MAX(diff, 0);
	t_color diffuse = v_multiply(rec->sphere.color, diff);
	
	// specular
	reflected = v_minus(sphere_to_light, v_multiply(rec->normal, 2 * v_dot(sphere_to_light, rec->normal)));
	spec = pow(MAX(v_dot(r.dir, reflected), 0.0000000), 500);
	specular_strength = 0.5;
	t_color specular = v_multiply(light->color, MAX(specular_strength * spec, 0));
	// printf("specular : %.15f\n", spec);
	// printf("%f\n", diffuse);

	t_color result = v_plus(v_plus(ambient, diffuse), specular);

	result = v_multiply_2(result, rec->sphere.color);
	result.x = MIN(MAX(result.x, 0), 1);
	result.y = MIN(MAX(result.y, 0), 1);
	result.z = MIN(MAX(result.z, 0), 1);

	// printf("%f %f %f\n", result.x, result.y, result.z);
	// phong = ((ambient + phong) > 1) ? 1 : ambient + phong + specular;
	return (result);
}

t_color		ray_color(t_ray r, t_objects *objects, t_sphere *light)
{
	t_hit_record	rec;
	double			t;
	t_vec			unit_direction;
	t_vec			normal;

	rec.t_max = INFINITY;
	rec.t_min = 0;
	if (hit_sphere(r, light, &rec))
		return (light->color);
	else if (hit(r, objects, &rec))
		return (phong_color(r, (t_sphere *)objects->object, light, &rec));
	return (color(0, 0, 0));
}