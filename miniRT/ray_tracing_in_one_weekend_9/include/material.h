/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:56:07 by root              #+#    #+#             */
/*   Updated: 2020/12/06 17:18:02 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# define LAMBERTIAN 1
# define METAL 2

# include "vec.h"
# include "hittable.h"

typedef struct s_hit_record t_hit_record;

typedef struct	s_material
{
	int			mat_kind;
	t_color		albedo;
}				t_material;

t_material	make_material(int mat_kind, t_color albedo);
int			lambertian_scatter(t_ray r_in, t_hit_record *rec, t_color *attenutaion, t_ray *scattered);
int			metal_scatter(t_ray r_in, t_hit_record *rec, t_color *attenutaion, t_ray *scattered);
int			scatter(t_ray r_in, t_hit_record *rec, t_color *attenuation, t_ray *scattered);
#endif