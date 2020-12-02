/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:40:24 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 18:26:28 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

#include "vec.h"
#include "ray.h"
#include "color.h"

typedef struct	s_hit_record
{
	t_point		p;
	t_vec		normal;
	double		t;
	double		t_min;
	double		t_max;
}				t_hit_record;

t_color		ray_color(t_ray r);

#endif