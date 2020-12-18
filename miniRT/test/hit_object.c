/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:45:23 by root              #+#    #+#             */
/*   Updated: 2020/12/18 01:34:04 by hyongti          ###   ########.fr       */
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

int		hit_plane(t_ray r, t_plane *plane, t_hit_record *rec)
{
	double	denom;
	double	t;
	t_vec	to_hit;

	denom = v_dot(plane->normal, r.dir);
	if (fabs(denom) < 1e-6)
	 	return (FALSE);
	to_hit = v_minus(plane->point, r.origin);
	t = v_dot(to_hit, plane->normal) / denom;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->p = at(rec->t, r);
	rec->normal = plane->normal;
	set_face_normal(r, rec);
	rec->color = plane->color;
	return (TRUE);
}

int			hit_triangle(t_ray r, t_triangle *triangle, t_hit_record *rec)
{
	t_vec   p1p2;	
	t_vec   p1p3;
	t_vec   normal;

	//compute plane's normal
	p1p2 = v_minus(triangle->p2, triangle->p1);
	p1p3 = v_minus(triangle->p3, triangle->p1);
	normal = v_normalize(v_cross(p1p2, p1p3));
	// normal = v_normalize(normal);

   //Step 1 : finding P
	double	denom;
	double	t;
	t_vec	to_hit;

	denom = v_dot(normal, r.dir);
	if (fabs(denom) < 1e-6)
	 	return (FALSE);
	to_hit = v_minus(triangle->p1, r.origin);
	t = v_dot(to_hit, normal) / denom;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);

   t_point   p;

   p = at(t, ray(r.origin, v_multiply(r.dir, t)));

   //Step 2 : inside-outside test
   t_vec   c;

   //edge 1;
   t_vec   edge1;
   t_vec   p_p1;

   edge1 = v_minus(triangle->p2, triangle->p1);
   p_p1 = v_minus(p, triangle->p1);
   c = v_cross(edge1, p_p1);
   if (v_dot(normal, c) < 0)
	  return (FALSE);

   //edge 2;
   t_vec   edge2;
   t_vec   p_p2;

   edge2 = v_minus(triangle->p3, triangle->p2);
   p_p2 = v_minus(p, triangle->p2);
   c = v_cross(edge2, p_p2);
   if (v_dot(normal, c) < 0)
	  return (FALSE);

   //edge 3;
   t_vec   edge3;
   t_vec   p_p3;

   edge3 = v_minus(triangle->p1, triangle->p3);
   p_p3 = v_minus(p, triangle->p3);
   c = v_cross(edge3, p_p3);
   if (v_dot(normal, c) < 0)
	  return (FALSE);

   if (t < rec->t_min || t > rec->t_max)
	  return (FALSE);
   rec->t = t;
   rec->normal = normal;
   set_face_normal(r, rec);
   rec->color = triangle->color;
   rec->p = p;
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
		rec->color = cylinder->color;
		set_face_normal(r, rec);
		center_len = sqrt(v_len_squared(v_minus(rec->p, cylinder->p)) - cylinder->radius * cylinder->radius);
		if (center_len < cylinder->len)
		{
			if (v_dot(cylinder->center_vec, v_minus(rec->p, cylinder->p)) >= 0)
				rec->normal = v_normalize(v_multiply(v_minus(rec->p, at(center_len, ray(cylinder->p, cylinder->center_vec))), 1 / cylinder->radius));
			else
			 	return (FALSE);
		}
		else if (center_len >= cylinder->len)
		{
			root = (-b + sqrtd) / a;
			rec->t = root;
			rec->p = at(rec->t, r);
			center_len = sqrt(v_len_squared(v_minus(rec->p, cylinder->p)) - cylinder->radius * cylinder->radius);
			if (center_len < cylinder->len)
			{
				if (v_dot(cylinder->center_vec, v_minus(rec->p, cylinder->p)) >= 0)
				{
					rec->normal = v_normalize(v_multiply(v_minus(rec->p, at(center_len, ray(cylinder->p, cylinder->center_vec))), 1 / cylinder->radius));
					rec->color = cylinder->color;
					set_face_normal(r, rec);
				}
				else
				 	return (FALSE);
			}
			else
				return (FALSE);
		}
		// rec->color = cylinder->color;
		// set_face_normal(r, rec);
		return (TRUE);
	}
}

int			hit_square(t_ray r, t_square *square, t_hit_record *rec)
{
	t_vec	half_horizontal;
	t_vec	half_vertical;
	t_point	a;
	t_point	b;
	t_point	c;
	t_point	d;
	
	half_horizontal = v_multiply(v_normalize(v_cross(v_minus(square->p, point(square->p.x, 0 ,square->p.z)), square->normal)), square->side_len / 2.0);
	half_vertical = v_multiply(v_normalize(v_cross(half_horizontal, square->normal)), square->side_len / 2.0);
	a = v_plus(v_plus(square->p, half_horizontal), half_vertical);
	b = v_plus(v_minus(square->p, half_horizontal), half_vertical);
	c = v_minus(v_minus(square->p, half_horizontal), half_vertical);
	d = v_minus(v_plus(square->p, half_horizontal), half_vertical);
	
	//Step 1 : finding P
	double	denom;
	double	t;
	t_vec	to_hit;

	denom = v_dot(square->normal, r.dir);
	if (fabs(denom) < 1e-6)
	{
		// printf("test denom test denom test denom\n");
		return (FALSE);
	}

	to_hit = v_minus(square->p, r.origin);
	t = v_dot(to_hit, square->normal) / denom;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);

	t_point   p;

	p = at(t, ray(r.origin, v_multiply(r.dir, t)));

	t_vec	e;
	//edge 1;
   t_vec   edge1;
   t_vec   pa;

	edge1 = v_minus(b, a);
	pa = v_minus(p, a);
	e = v_cross(edge1, pa);
	if (v_dot(square->normal, e) < 0)
	{
		// printf("test1 test1 test1\n");
		return (FALSE);
	}


   //edge 2;
	t_vec	edge2;
	t_vec	pb;

	edge2 = v_minus(c, b);
	pb = v_minus(p, b);
	e = v_cross(edge2, pb);
	if (v_dot(square->normal, e) < 0)
	{
		// printf("test2 test2 test2\n");
		return (FALSE);
	}


   //edge 3;
   	t_vec	edge3;
	t_vec	pc;

	edge2 = v_minus(d, c);
	pc = v_minus(p, c);
	e = v_cross(edge3, pc);
	if (v_dot(square->normal, e) < 0)
	{
		// printf("test3 test3 test3\n");
		return (FALSE);
	}

	 //edge 4;
   	t_vec	edge4;
	t_vec	pd;

	edge2 = v_minus(a, d);
	pd = v_minus(p, d);
	e = v_cross(edge4, pd);
	if (v_dot(square->normal, e) < 0)
	{
		// printf("test4 test4 test4\n");
		return (FALSE);
	}


	rec->t = t;
	rec->normal = square->normal;
	set_face_normal(r, rec);
	rec->color = square->color;
	rec->p = p;
	return (TRUE);
}