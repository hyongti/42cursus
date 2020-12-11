/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:20:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/11 15:24:37 by root             ###   ########.fr       */
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
	else if (objects->type == CY)
	{
		// printf("test test test test test test\n");
		hit_result = hit_cylinder(r, (t_cylinder *)objects->object, rec);
	}
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