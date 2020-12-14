/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:45:23 by root              #+#    #+#             */
/*   Updated: 2020/12/14 21:45:46 by root             ###   ########.fr       */
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
		// rec->sphere.center = sphere->center;
		rec->color = sphere->color;
		//printf("%f\n", v_dot(r.dir, rec->normal));
		set_face_normal(r, rec);
		return (TRUE);
	}
}

int			hit_triangle(t_ray r, t_triangle *triangle, t_hit_record *rec)
{
	t_vec	p1p2;
	t_vec	p1p3;
	t_vec	normal;

	//compute plane's normal
	p1p2 = v_minus(triangle->p2, triangle->p1);
	p1p3 = v_minus(triangle->p3, triangle->p1);
	normal = v_cross(p1p2, p1p3);
	// normal = v_normalize(normal);

	//Step 1 : finding P
	//check if ray and plane are parallel
	double	parallel;

	parallel = v_dot(normal, r.dir);
	// if (v_dot(normal, r.dir) < 0)
	// 	parallel = v_dot(normal, v_multiply(r.dir, -1));
	if (fabs(parallel) < 1e-6)
		return (FALSE);

	//compute d parameter using equation 2
	double	d;
	double	t;

	d = v_dot(normal, v_minus(triangle->p1, r.origin));
	t = (v_dot(normal, r.origin) + d) / parallel;
	
	// printf("t : %f\n", t);
	if (t < 0)
		return (FALSE);
	
	//compute the intersection point using equation 1
	rec->p = at(t, ray(r.origin, v_multiply(r.dir, t)));

	//Step 2 : inside-outside test
	t_vec	c;

	//edge 1;
	t_vec	edge1;
	t_vec	p_p1;

	edge1 = v_minus(triangle->p2, triangle->p1);
	p_p1 = v_minus(rec->p, triangle->p1);
	c = v_cross(edge1, p_p1);
	if (v_dot(normal, c) > 0)
		return (FALSE);

	//edge 2;
	t_vec	edge2;
	t_vec	p_p2;

	edge2 = v_minus(triangle->p3, triangle->p2);
	p_p2 = v_minus(rec->p, triangle->p2);
	c = v_cross(edge2, p_p2);
	if (v_dot(normal, c) > 0)
		return (FALSE);

	//edge 3;
	t_vec	edge3;
	t_vec	p_p3;

	edge3 = v_minus(triangle->p1, triangle->p3);
	p_p3 = v_minus(rec->p, triangle->p3);
	c = v_cross(edge3, p_p3);
	if (v_dot(normal, c) > 0)
		return (FALSE);

	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->normal = normal;
	set_face_normal(r, rec);
	rec->color = triangle->color;
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
	double	center_len;
	t_vec	del_p;

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
		rec->t = root;
		rec->p = at(rec->t, r);
		center_len = sqrt(v_len_squared(v_minus(rec->p, cylinder->p)) - cylinder->radius * cylinder->radius);
		if (center_len < (cylinder->len / 2))
		{
			if (v_dot(cylinder->center_vec, v_minus(rec->p, cylinder->p)) >= 0)
				rec->normal = v_multiply(v_minus(rec->p, at(center_len, ray(cylinder->p, cylinder->center_vec))), 1 / cylinder->radius);
			else
				rec->normal = v_multiply(v_minus(rec->p, at(-1 * center_len, ray(cylinder->p, cylinder->center_vec))), 1 / cylinder->radius);
		}
		else if (center_len >= (cylinder->len / 2))
		{
			root = (-b + sqrtd) / a;
			rec->t = root;
			rec->p = at(rec->t, r);
			center_len = sqrt(v_len_squared(v_minus(rec->p, cylinder->p)) - cylinder->radius * cylinder->radius);
			if (center_len < (cylinder->len / 2))
			{
				if (v_dot(cylinder->center_vec, v_minus(rec->p, cylinder->p)) >= 0)
					rec->normal = v_multiply(v_minus(rec->p, at(center_len, ray(cylinder->p, cylinder->center_vec))), 1 / cylinder->radius);
				else
					rec->normal = v_multiply(v_minus(rec->p, at(-1 * center_len, ray(cylinder->p, cylinder->center_vec))), 1 / cylinder->radius);
			}
			else
				return (FALSE);
		}
		rec->color = cylinder->color;
		set_face_normal(r, rec);
		return (TRUE);
	}
}

int		hit_plane(t_ray r, t_plane *plane, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_vec	to_hit;

	if (v_dot(plane->normal, v_normalize(r.dir)) < 0)
		plane->normal = v_multiply(plane->normal, -1);
	denom = v_dot(plane->normal, v_normalize(r.dir));
	// printf("denom : %f\n", denom);
	// printf("1e-6 : %f\n", 1e-6);
	if (denom > 1e-6)
	{
		to_hit = v_minus(plane->point, r.origin);
		t = v_dot(to_hit, plane->normal);
		// printf("t : %f\n", t);
		if (t < rec->t_min || t > rec->t_max)
		{
			// printf("1111111111111111\n");
			return (FALSE);
		}
	}
	else
	{
		// printf("22222222222222222222222222222\n");
		return (FALSE);
	}
	// printf("3333333333333333333333\n");
	rec->t = t;
	rec->p = at(rec->t, r);
	rec->normal = plane->normal;
	// rec->normal = plane->normal;
	// rec->sphere.center = sphere->center;
	rec->color = plane->color;
	//printf("%f\n", v_dot(r.dir, rec->normal));
	set_face_normal(r, rec);
	return (TRUE);
}