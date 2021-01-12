/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:01:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/12 20:54:27 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static void get_sphere_uv(t_hit_record *rec)
{
	double	theta;
	double	phi;
	// double	sine;

	theta = acos(-(rec->normal.y));
	phi = atan2(-(rec->normal.z), rec->normal.x) + PI;
	rec->u = phi / (2 * PI);
	rec->v = theta / PI;
	// sine = sin(50 * rec->u) * sin(50 * rec->v);
}

int			hit_sphere(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	t_sphere *sphere;

	sphere = (t_sphere *)obj->object;
	oc = v_minus(r->origin, sphere->center);
	a = v_dot(r->dir, r->dir);
	b = v_dot(oc, r->dir);
	c = v_dot(oc, oc) - sphere->radius * sphere->radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (FALSE);
	else
	{
		sqrtd = sqrt(discriminant);
		root = (-b - sqrtd) / a;
		if (root < rec->t_min || root > rec->t_max)
		{
			root = (-b + sqrtd) / a;
			if (root < rec->t_min || root > rec->t_max)
				return (FALSE);
		}
	}
	get_record(rec, root, obj, r);
	rec->normal = v_normalize(v_minus(rec->p, sphere->center));
	set_face_normal(*r, rec);
	get_sphere_uv(rec);
	return (TRUE);
}