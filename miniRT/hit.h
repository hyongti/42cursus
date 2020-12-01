/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:55:11 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/11/30 20:05:21 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

#include "vec.h"
#include "useful_nbr.h"

typedef struct	s_sphere
{
	t_vec		center;
	double		radius;
}				t_sphere;

typedef struct	s_record
{
	double		t;
	t_vec		p;
	t_vec		normal;
}				t_record;

int		hit_sphere(t_vec origin, t_vec ray, t_sphere sphere, t_record *record);
void	set_face_normal(t_vec *ray, t_record *rec);

#endif