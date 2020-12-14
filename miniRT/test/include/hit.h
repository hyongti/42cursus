/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/13 01:11:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

#include "vector_utils.h"
#include "ray.h"
#include "color.h"
#include "hit.h"
#include "light.h"
#include "objects.h"
#include <unistd.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	t_color		color;
	int			front_face;
	double		t;
	double		t_min;
	double		t_max;
	int			type;
}				t_hit_record;

void		set_face_normal(t_ray r, t_hit_record *rec);
int			hit_sphere(t_ray r, t_sphere *sphere, t_hit_record *rec);
int			hit_triangle(t_ray r, t_triangle *triangle, t_hit_record *rec);
int			hit_cylinder(t_ray r, t_cylinder *cylinder, t_hit_record *rec);
int			hit_plane(t_ray r, t_plane *plane, t_hit_record *rec);
int			hit_objects(t_ray r, t_objects *objects, t_hit_record *rec);
int			hit(t_ray r, t_objects *objects, t_hit_record *rec);
t_color		ray_color(t_ray r, t_objects *objects);

#endif