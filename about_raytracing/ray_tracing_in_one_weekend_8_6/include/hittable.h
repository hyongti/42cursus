/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 14:57:16 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

#include "vec.h"
#include "ray.h"
#include "color.h"
#include "hittable.h"
#include "hittable_list.h"
#include "random.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	int			front_face;
	double		t;
	double		t_min;
	double		t_max;
}				t_hit_record;

void		set_face_normal(t_ray r, t_hit_record *rec);
double		hit_sphere(t_ray r, t_sphere *sphere, t_hit_record *rec);
int			hit(t_ray r, t_hittable_list *world, t_hit_record *rec);
int			hit_list(t_ray r, t_hittable_list *world, t_hit_record *rec);
t_color		ray_color(t_ray r, t_hittable_list *world, int depth);

#endif