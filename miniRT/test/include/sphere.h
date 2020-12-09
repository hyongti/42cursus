/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/08 11:03:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "vector_utils.h"

typedef struct	s_sphere
{
	t_point		center;
	double		radius;
	t_color		color;
}				t_sphere;

t_sphere	*sphere(t_point center, double radius, t_color color);


#endif