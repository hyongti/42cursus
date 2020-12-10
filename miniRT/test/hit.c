/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:20:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/09 23:21:07 by hyongti          ###   ########.fr       */
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
		rec->sphere.center = sphere->center;
		rec->color = sphere->color;
		rec->type = SP;
		//printf("%f\n", v_dot(r.dir, rec->normal));
		set_face_normal(r, rec);
		return (TRUE);
	}
}

int			hit_triangle(t_ray r, t_triangle *triangle, t_hit_record *rec)
{
	rec->normal = v_cross(v_minus(triangle->p1, triangle->p2), v_minus(triangle->p1, triangle->p3));
 	set_face_normal(r, rec);
	
	t_vec	c;

	double	d = v_dot(rec->normal, triangle->p1);

	double	root = (v_dot(rec->normal, r.origin) + d) / v_dot(rec->normal, r.dir);
	if (root < 0)
		return (FALSE);
	// printf("test1111111\n");
	
	t_point p = at(root, r);

	t_vec edge1 = v_minus(triangle->p2, triangle->p1);
	t_vec p_p1 = v_minus(p, triangle->p1);
	c = v_cross(edge1, p_p1);
	if (v_dot(rec->normal, c) < 0)
		return (FALSE);
	// printf("test2222222222\n");
	t_vec edge2 = v_minus(triangle->p3, triangle->p2);
	t_vec p_p2 = v_minus(p, triangle->p2);
	c = v_cross(edge2, p_p2);
	if (v_dot(rec->normal, c) < 0)
		return (FALSE);
	// printf("test3333333333\n");
	t_vec edge3 = v_minus(triangle->p1, triangle->p3);
	t_vec p_p3 = v_minus(p, triangle->p3);
	c = v_cross(edge3, p_p3);
	if (v_dot(rec->normal, c) < 0)
		return (FALSE);
	// printf("test44444444444\n");

	if (root < rec->t_min || root > rec->t_max)
		return (FALSE);
	rec->p = p;
	rec->type = TR;
	rec->t = root;
	rec->color = triangle->color;
	return (TRUE);
}


int			hit_objects(t_ray r, t_objects *objects, t_hit_record *rec)
{
	int		hit_result;

	hit_result = FALSE;
	if (objects->type == SP)
		hit_result = hit_sphere(r, (t_sphere *)objects->object, rec);
	else if (objects->type == LIGHT)
		hit_result = FALSE;
	else if (objects->type == TR)
		hit_result = hit_triangle(r, (t_triangle *)objects->object, rec);
	return (hit_result);

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

static t_vec	reflect(t_vec v, t_vec n)
{
	//v - 2 * dot(v, n) * n;
	return (v_minus(v, v_multiply(n ,v_dot(v, n) * 2)));
}

static t_color	phong_color_cal(t_ray r, t_light *light, t_hit_record *rec)
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_vec		light_dir;
	t_vec		view_dir;
	t_vec		reflect_dir;
	t_vec		unit_norm;

	double		ka;
	double		kd;
	double		ks;
	double		ksn;
	double		spec;
	unit_norm = v_normalize(rec->normal);
	view_dir = v_normalize(v_multiply(r.dir, -1));
	light_dir = v_normalize(v_minus(light->point, rec->p));
	reflect_dir = reflect(v_multiply(light_dir, -1), unit_norm);
	ka = 0.1; // ambient strength;
	kd = fmax(v_dot(unit_norm, light_dir), 0.0);// diffuse strength;
	ks = 0.5; // specular strength;
	ksn = 512;
	ambient = v_multiply(light->color, ka);
	diffuse = v_multiply(light->color, kd);
	spec = pow(fmax(v_dot(view_dir, reflect_dir), 0.0), ksn);
	specular = v_multiply(v_multiply(light->color, kd), spec);

	return (v_plus(v_plus(ambient, diffuse), specular));
	
	// t_vec			to_light;
	// t_vec			reflected;
	// double			ambient_strength;
	// double			phong;
	// double			diff;
	// double			spec;
	// double			specular_strength;
	
	// // printf("%f %f %f\n", rec->sphere.center.x, rec.sphere.center.y, rec.sphere.center.z);

	// // ambient;
	// ambient_strength = 0.1;
	// t_color ambient = v_multiply(light->color, ambient_strength);

	// // diffuse
	
	// if (rec->type == SP)
	// 	to_light = v_normalize(v_minus(light->point, rec->sphere.center));
	// if (rec->type == TR)
	// 	to_light = v_normalize(v_minus(light->point, rec->p));
	// diff = v_dot(to_light, rec->normal);
	// diff = MAX(diff, 0);
	// t_color diffuse = v_multiply(rec->color, diff);
	
	// // specular
	// reflected = v_minus(to_light, v_multiply(rec->normal, 2 * v_dot(to_light, rec->normal)));
	// spec = pow(MAX(v_dot(r.dir, reflected), 0), 256);
	// specular_strength = 0.5;
	// t_color specular = v_multiply(light->color, MAX(specular_strength * spec, 0));
	// // printf("specular : %.15f\n", spec);
	// // printf("%f\n", diffuse);

	// t_color result = v_plus(v_plus(ambient, diffuse), specular);

	// result = v_multiply_2(result, rec->color);


	// // printf("%f %f %f\n", result.x, result.y, result.z);
	// // phong = ((ambient + phong) > 1) ? 1 : ambient + phong + specular;
	// return (result);
}

static t_color	phong_color(t_ray r, t_objects *objects, t_hit_record *rec)
{
	t_color		light_color;

	light_color = color(0, 0, 0);

	while (objects)
	{
		if (objects->type == LIGHT)
			light_color = v_plus(light_color, phong_color_cal(r, objects->object, rec));
		objects = objects->next;
	}
	light_color = v_multiply_2(light_color, rec->color);
	light_color.x = fmin(light_color.x, 1);
	light_color.y = fmin(light_color.y, 1);
	light_color.z = fmin(light_color.z, 1);

	return (light_color);	
}

t_color		ray_color(t_ray r, t_objects *objects)
{
	t_hit_record	rec;
	double			t;
	t_vec			unit_direction;
	t_vec			normal;

	rec.t_max = INFINITY;
	rec.t_min = 0;
	if (hit(r, objects, &rec))
	{
		if (objects->type == LIGHT)
			return (((t_light *)(objects->object))->color);
		return (phong_color(r, objects, &rec));
	}
	unit_direction = v_normalize(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (v_plus(v_multiply(color(1, 1, 1), 1.0 - t), v_multiply(color(0.5, 0.7, 1.0), t)));
}