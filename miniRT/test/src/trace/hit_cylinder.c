/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder->c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:00:32 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/10 23:25:37 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static void	get_cylinder_uv(t_hit_record *rec, t_cylinder *cylinder, double len)
{
	double	phi;
	double  sines;

	phi = 0.0;
	if (is_aligned(cylinder->vec) == X)
		phi = atan2(-(rec->normal.y), rec->normal.z) + PI;
	else if (is_aligned(cylinder->vec) == Y)
		phi = atan2(-(rec->normal.z), rec->normal.x) + PI;
	else if (is_aligned(cylinder->vec) == Z)
		phi = atan2(-(rec->normal.x), rec->normal.y) + PI;
	rec->u = phi / (2 * PI);
	rec->v = len / cylinder->len;
	sines = sin(50 * rec->u) * sin(50 * rec->v);
}

int		hit_disc(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_cylinder *cylinder;
	t_vec	to_hit;
	t_point	p;

	cylinder = (t_cylinder *)obj->object;
	denom = v_dot(cylinder->vec, r->dir);
	if (fabs(denom) < 1e-6)
	 	return (FALSE);
	if (cylinder->vec.z < 0)
	{
		to_hit = v_minus(cylinder->p, r->origin);
		t = v_dot(to_hit, cylinder->vec) / denom;
	}
	else
	{
		to_hit = v_minus(v_plus(cylinder->p, v_multiply(cylinder->vec, cylinder->len)), r->origin);
		t = v_dot(to_hit, cylinder->vec) / denom;
	}
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	p = at(t, *r);
	if (cylinder->vec.z < 0)
	{
		if (v_len_squared(v_minus(cylinder->p, p)) > cylinder->radius * cylinder->radius)
			return (FALSE);
	}
	else
	{
		if (v_len_squared(v_minus(v_plus(cylinder->p, v_multiply(cylinder->vec, cylinder->len)), p)) > cylinder->radius * cylinder->radius)
			return (FALSE);
	}
	
	rec->normal = cylinder->vec;
	get_record(rec, t, obj, r);
	set_face_normal(*r, rec);
	return (TRUE);
}

int			hit_cylinder(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	double	len;
	t_cylinder	*cylinder;
	t_vec	n;
	t_vec	del_p;
	t_point	p;

	cylinder = (t_cylinder *)obj->object;
	del_p = v_minus(r->origin, cylinder->p);
	cylinder->vec = v_normalize(cylinder->vec);
	a = v_len_squared(v_minus(r->dir, v_multiply(cylinder->vec, v_dot(r->dir, cylinder->vec))));
	b = v_dot(v_minus(r->dir, v_multiply(cylinder->vec, v_dot(r->dir, cylinder->vec))), 
				v_minus(del_p, v_multiply(cylinder->vec, v_dot(del_p, cylinder->vec))));
	c = v_len_squared(v_minus(del_p, v_multiply(cylinder->vec, v_dot(del_p, cylinder->vec))))
				- cylinder->radius * cylinder->radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-b - sqrtd) / a;
	if (root < rec->t_min || root > rec->t_max)
		return (FALSE);
	p = at(root, *r);
	if (!(len = v_dot(v_minus(p, cylinder->p), cylinder->vec)))
		return (FALSE);
	if (len <= cylinder->len && len > 0)
		n = v_normalize(v_minus(p, at(len, ray(cylinder->p, cylinder->vec))));
	else
	{
		if (hit_disc(r, obj, rec) == TRUE)
			return (TRUE);
		root = (-b + sqrtd) / a;
		p = at(root, *r);
		if ((len = v_dot(v_minus(p, cylinder->p), cylinder->vec)) < 0)
			return (FALSE);
		if (len <= cylinder->len)
			n = v_normalize(v_minus(p, at(len, ray(cylinder->p, cylinder->vec))));
		else
			return (FALSE);
	}
	get_record(rec, root, obj, r);
	rec->normal = n;
	set_face_normal(*r, rec);
	if (is_aligned(cylinder->vec) != FALSE)
		get_cylinder_uv(rec, cylinder, len);
	// printf("test\n");
	return (TRUE);
}