/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:06:29 by root              #+#    #+#             */
/*   Updated: 2020/12/06 19:20:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

t_material	make_material(int mat_kind, t_color albedo)
{
	t_material	material;

	material.mat_kind = mat_kind;
	material.albedo = albedo;
	return (material);
}

int		by_lambertian(t_ray r_in, t_hit_record *rec, t_color *attenuation, t_ray *scattered)
{
	t_vec	scatter_direction;
	
	scatter_direction = v_plus(rec->normal, random_unit_vector());
	*scattered = ray(rec->p, scatter_direction);
	*attenuation = rec->material.albedo;
	return (1);
}

int		by_metal(t_ray r_in, t_hit_record *rec, t_color *attenuation, t_ray *scattered)
{
	t_vec	reflected;

	reflected = reflect(v_normalize(r_in.dir), rec->normal);
	*scattered = ray(rec->p, reflected);
	*attenuation = rec->material.albedo;
	return (v_dot(scattered->dir, rec->normal) > 0);
}

int		scatter(t_ray r_in, t_hit_record *rec, t_color *attenuation, t_ray *scattered)
{
	// printf("mat_kind : %d\n", rec->material.mat_kind);
	if (rec->material.mat_kind == LAMBERTIAN)
		return (by_lambertian(r_in, rec, attenuation, scattered));
	if (rec->material.mat_kind == METAL)
		return (by_metal(r_in, rec, attenuation, scattered));
	return (0);
}