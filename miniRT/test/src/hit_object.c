/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:45:23 by root              #+#    #+#             */
/*   Updated: 2021/01/04 11:04:55 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

int			hit_sphere(t_ray r, t_sphere *sphere, t_hit_record *rec)
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
		sqrtd = sqrt(discriminant);
		root = (-b - sqrtd) / a;
		if (root < rec->t_min || root > rec->t_max)
		{
			root = (-b + sqrtd) / a;
			if (root < rec->t_min || root > rec->t_max)
				return (FALSE);
		}
	}
	rec->t = root;
	rec->p = at(rec->t, r);
	rec->normal = v_multiply(v_minus(rec->p, sphere->center), 1 / sphere->radius);
	rec->color = sphere->color;
	set_face_normal(r, rec);
	return (TRUE);
}

int		hit_plane(t_ray r, t_plane *plane, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_vec	to_hit;

	denom = v_dot(plane->n, r.dir);
	if (fabs(denom) < 1e-6)
	 	return (FALSE);
	to_hit = v_minus(plane->point, r.origin);
	t = v_dot(to_hit, plane->n) / denom;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->p = at(t, r);
	rec->normal = plane->n;
	rec->color = plane->color;
	set_face_normal(r, rec);
	return (TRUE);
}

int			hit_triangle(t_ray r, t_triangle *triangle, t_hit_record *rec)
{
	double	t;
	t_point	p;

	t = v_dot(v_minus(triangle->p1, r.origin), triangle->n) / v_dot(triangle->n, r.dir);
	if (t < 0)
		return (0);
	if (t < rec->t_min || t > rec->t_max)
		return (0);
	p = at(t, r);

	if (!(is_inside(triangle->p1, triangle->p2, triangle->p3, p)))
		return (FALSE);
	rec->t = t;
	rec->normal = triangle->n;
	rec->color = triangle->color;
	rec->p = p;
	set_face_normal(r, rec);
	return (TRUE);
}

static	int	hit_disc(t_ray r, t_cylinder *cylinder, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_vec	to_hit;
	t_point	p;

	denom = v_dot(cylinder->center_vec, r.dir);
	if (fabs(denom) < 1e-6)
	 	return (FALSE);
	if (cylinder->center_vec.z < 0)
	{
		to_hit = v_minus(cylinder->p, r.origin);
		t = v_dot(to_hit, cylinder->center_vec) / denom;
	}
	else
	{
		to_hit = v_minus(v_plus(cylinder->p, v_multiply(cylinder->center_vec, cylinder->len)), r.origin);
		t = v_dot(to_hit, cylinder->center_vec) / denom;
	}
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	p = at(t, r);
	if (cylinder->center_vec.z < 0)
	{
		if (v_len_squared(v_minus(cylinder->p, p)) > cylinder->radius * cylinder->radius)
			return (FALSE);
	}
	else
	{
		if (v_len_squared(v_minus(v_plus(cylinder->p, v_multiply(cylinder->center_vec, cylinder->len)), p)) > cylinder->radius * cylinder->radius)
			return (FALSE);
	}
	
	rec->t = t;
	rec->p = at(t, r);
	rec->normal = cylinder->center_vec;
	rec->color = cylinder->color;
	set_face_normal(r, rec);
	return (TRUE);
}

int			hit_cylinder(t_ray r, t_cylinder *cylinder, t_hit_record *rec)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
	double	len;
	t_vec	n;
	t_vec	del_p;
	t_point	p;

	if (hit_disc(r, cylinder, rec) != 0)
		return (TRUE);
	del_p = v_minus(r.origin, cylinder->p);
	cylinder->center_vec = v_normalize(cylinder->center_vec);
	a = v_len_squared(v_minus(r.dir, v_multiply(cylinder->center_vec, v_dot(r.dir, cylinder->center_vec))));
	b = v_dot(v_minus(r.dir, v_multiply(cylinder->center_vec, v_dot(r.dir, cylinder->center_vec))), 
				v_minus(del_p, v_multiply(cylinder->center_vec, v_dot(del_p, cylinder->center_vec))));
	c = v_len_squared(v_minus(del_p, v_multiply(cylinder->center_vec, v_dot(del_p, cylinder->center_vec))))
				- cylinder->radius * cylinder->radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-b - sqrtd) / a;
	if (root < rec->t_min || root > rec->t_max)
		return (FALSE);
	p = at(root, r);
	if (!(len = v_dot(v_minus(p, cylinder->p), cylinder->center_vec)))
		return (FALSE);
	if (len <= cylinder->len && len > 0)
		n = v_normalize(v_minus(p, at(len, ray(cylinder->p, cylinder->center_vec))));
	else
	{
		root = (-b + sqrtd) / a;
		p = at(root, r);
		if ((len = v_dot(v_minus(p, cylinder->p), cylinder->center_vec)) < 0)
			return (FALSE);
		if (len <= cylinder->len)
			n = v_normalize(v_minus(p, at(len, ray(cylinder->p, cylinder->center_vec))));
		else
			return (FALSE);
	}
	rec->p = p;
	rec->t = root;
	rec->color = cylinder->color;
	rec->normal = n;
	set_face_normal(r, rec);
	return (TRUE);
}


int			hit_square(t_ray r, t_square *square, t_hit_record *rec)
{
	t_vec	half_horizontal;
	t_vec	half_vertical;
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_point	p4;
	double	root;
	t_point	p;
	
	// printf("%f %f %f\n", square->p.x, square->p.y, square->p.z);
	half_horizontal = v_multiply(v_normalize(v_cross(v_minus(square->p, point(square->p.x, 0 ,square->p.z)), square->n)), square->side_len / 2.0);
	half_vertical = v_multiply(v_normalize(v_cross(square->n, half_horizontal)), square->side_len / 2.0);
	// printf("horizontal : %f %f %f\n", half_horizontal.x, half_horizontal.y, half_horizontal.z);
	// printf("vertical : %f %f %f\n", half_vertical.x, half_vertical.y, half_vertical.z);
	p1 = v_plus(v_plus(square->p, half_horizontal), half_vertical);
	p2 = v_plus(v_minus(square->p, half_horizontal), half_vertical);
	p3 = v_minus(v_minus(square->p, half_horizontal), half_vertical);
	p4 = v_minus(v_plus(square->p, half_horizontal), half_vertical);
	// printf("	x		y		z\n");
	// printf("p1 %f		%f		%f\n", p1.x, p1.y, p1.z);
	// printf("p2 %f		%f		%f\n", p2.x, p2.y, p2.z);
	// printf("p3 %f		%f		%f\n", p3.x, p3.y, p3.z);
	// printf("p4 %f		%f		%f\n", p4.x, p4.y, p4.z);
	root = v_dot(v_minus(square->p, r.origin), square->n) / v_dot(square->n, r.dir);
	if (root < 0)
		return (0);
	if (root < rec->t_min || root > rec->t_max)
		return (0);
	p = at(root, r);
	if (!is_inside(p4, p3, p2, p) && !(is_inside(p4, p2, p1, p)))
	{
		// printf("test\n");
		return (FALSE);
	}
	rec->t = root;
	rec->normal = square->n;
	rec->color = square->color;
	rec->p = p;
	set_face_normal(r, rec);
	return (TRUE);
}

int			hit_cone(t_ray r, t_cone *cone, t_hit_record *rec)
{
	t_vec	co = v_minus(r.origin, cone->p);
	// double cosa = cos(cone->angle);
	double cosa = cos(deg_to_rad(cone->angle));
	
	double a = v_dot(r.dir, cone->axis) * v_dot(r.dir, cone->axis) - cosa * cosa;
	double b = v_dot(r.dir, cone->axis) * v_dot(co, cone->axis) - v_dot(r.dir, co) * cosa * cosa;
	double c = v_dot(co, cone->axis) * v_dot(co, cone->axis) - v_dot(co, co) * cosa * cosa;

	double determinant = b * b - a * c;
	if (determinant < 0)
		return (FALSE);

	double sqrtd = sqrt(determinant);
	double root = (-b - sqrtd) / a;
	if (root > rec->t_max || root < rec->t_min)
	{
		root = (-b + sqrtd) / a;
		if (root > rec->t_max || root < rec->t_min)
			return (FALSE);
	}

	t_point p = at(root, r);
	t_vec cp = v_minus(p, cone->p);
	double h = v_dot(cp, cone->axis);

	if (h < 0 || h > cone->height)
		return (FALSE);

	t_vec n = v_normalize(v_minus(cp, v_multiply(cone->axis, v_len(cp) / cosa)));

	rec->p = p;
	rec->t = root;
	rec->color = cone->color;
	// printf("%f %f %f\n", rec->color.x, rec->color.y, rec->color.z);
	rec->normal = n;
	set_face_normal(r, rec);
	return (TRUE);
}