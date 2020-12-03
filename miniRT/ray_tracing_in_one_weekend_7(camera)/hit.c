/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:20:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 11:04:33 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

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
		//printf("%f\n", v_dot(r.dir, rec->normal));
		set_face_normal(r, rec);
		return (TRUE);
	}
}

int			hit(t_ray r, t_hittable_list *world, t_hit_record *rec)
{
	int		hit;

	hit = FALSE;
	if (world->type == SP)
		hit = hit_sphere(r, (t_sphere *)world->object, rec);
	return (hit);
}

int			hit_list(t_ray r, t_hittable_list *world, t_hit_record *rec)
{
	t_hit_record	tmp_rec;
	int				hit_anything;

	tmp_rec.t_min = rec->t_min;
	tmp_rec.t_max = rec->t_max;
	hit_anything = FALSE;
	while (world)
	{
		if (hit(r, world, rec))
		{
			hit_anything = TRUE;
			tmp_rec.t_max = tmp_rec.t;
			rec = &tmp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_color		ray_color(t_ray r, t_hittable_list *world)
{
	t_hit_record	rec;
	double			t;
	t_vec			unit_direction;
	
	rec.t_max = INFINITY;
	rec.t_min = 0;
	if (hit_list(r, world, &rec))
		return (v_multiply(v_plus(rec.normal, color(1, 1, 1)), 0.5));
	unit_direction = v_normalize(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (v_plus(v_multiply(color(1.0, 1.0, 1.0), (1.0 - t)), v_multiply(color(0.5, 0.7, 1.0), t)));
}