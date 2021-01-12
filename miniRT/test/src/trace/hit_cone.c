/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:01:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/12 20:53:55 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static void	get_cone_uv(t_hit_record *rec, t_cone *cone, double len)
{
	double	phi;
	double  sines;

	phi = 0.0;
	if (is_aligned(cone->axis) == X)
		phi = atan2(-(rec->normal.y), rec->normal.z) + PI;
	else if (is_aligned(cone->axis) == Y)
		phi = atan2(-(rec->normal.z), rec->normal.x) + PI;
	else if (is_aligned(cone->axis) == Z)
		phi = atan2(-(rec->normal.x), rec->normal.y) + PI;
	rec->u = phi / (2 * PI);
	rec->v = len / cone->height;
	sines = sin(50 * rec->u) * sin(50 * rec->v);
}

int			hit_cone(t_ray *r, t_objects *obj, t_hit_record *rec)
{
	t_cone	*cone;

	cone = (t_cone *)obj->object;
	t_point	pa = cone->p;
	t_vec	delp = v_minus(r->origin, pa);
	double	cosa = cos(deg_to_rad(cone->angle));
	double	sina = sin(deg_to_rad(cone->angle));

	double	a;
	double	b;
	double	c;
	
	a = cosa * cosa * v_len_squared(v_minus(r->dir, v_multiply(cone->axis, v_dot(r->dir, cone->axis))))
		- sina * sina * v_dot(r->dir, cone->axis) * v_dot(r->dir, cone->axis);
	b = cosa * cosa * v_dot(v_minus(r->dir, v_multiply(cone->axis, v_dot(r->dir, cone->axis))),
			v_minus(delp, v_multiply(cone->axis, v_dot(delp, cone->axis))))
			- sina * sina * v_dot(r->dir, cone->axis) * v_dot(delp, cone->axis);
	c = cosa * cosa * v_len_squared(v_minus(delp, v_multiply(cone->axis, v_dot(delp, cone->axis))))
		- sina * sina * v_dot(delp, cone->axis) * v_dot(delp, cone->axis);

	double	discriminant;
	double	sqrtd;
	double	root;
	double	len;
	t_point	p;
	t_vec	n;

	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-b - sqrtd) / a;
	if (root < rec->t_min || root > rec->t_max)
		return (FALSE);
	p = at(root, *r);
	if ((len = v_dot(cone->axis, v_minus(p, cone->p))) < 0)
		return (FALSE);
	if (len <= cone->height && len > 0)
		n = v_normalize(v_minus(p, at(len, ray(cone->p, cone->axis))));
	else
	{
		root = (-b + sqrtd) / a;
		p = at(root, *r);
		if ((len = v_dot(cone->axis, v_minus(p, cone->p))) < 0)
			return (FALSE);
		if (len <= cone->height)
			n = v_normalize(v_minus(p, at(len, ray(cone->p, cone->axis))));
		else
			return (FALSE);
	}

	get_record(rec, root, obj, r);
	rec->normal = n;
	set_face_normal(*r, rec);
	if (is_aligned(cone->axis) != FALSE)
		get_cone_uv(rec, cone, len);
	return (TRUE);
}

/*
** return (FALSE);
**	if (len <= cone->height && len > 0)
**	n = v_normalize(v_minus(p, at(len, ray(cone->p, cone->axis))));
**	else
**	{
**		root = (-b + sqrtd) / a;
**		p = at(root, *r);
**		if ((len = v_dot(cone->axis, v_minus(p, cone->p))) < 0)
**			return (FALSE);
**		if (len <= cone->height)
**			n = v_normalize(v_minus(p, at(len, ray(cone->p, cone->axis))));
**		else
**			return (FALSE);
**	}
*/
