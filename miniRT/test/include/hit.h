/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/08 19:47:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

#include "vector_utils.h"
#include "ray.h"
#include "color.h"
#include "hit.h"
#include "objects.h"

# define TRUE 1
# define FALSE 0

# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))

typedef struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	t_color		color;
	int			front_face;
	double		t;
	double		t_min;
	double		t_max;
	t_sphere	sphere;
}				t_hit_record;

void		set_face_normal(t_ray r, t_hit_record *rec);
double		hit_sphere(t_ray r, t_sphere *sphere, t_hit_record *rec);
int			hit_objects(t_ray r, t_objects *objects, t_hit_record *rec);
int			hit(t_ray r, t_objects *objects, t_hit_record *rec);
t_color		ray_color(t_ray r, t_objects *objects, t_sphere *light);

#endif