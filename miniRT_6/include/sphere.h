/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 20:48:52 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "hittable.h"
#include "vec.h"

typedef struct	s_sphere
{
    t_point		center;
	double		radius;
}				t_sphere;

double		hit_sphere(t_point center, double radius, t_ray r);

#endif
