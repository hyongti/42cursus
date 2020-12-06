/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/04 16:21:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "vec.h"
#include "material.h"

typedef struct	s_sphere
{
	t_point		center;
	double		radius;
	t_material	material;
}				t_sphere;

t_sphere	*sphere(t_point center, double radius, t_material material);


#endif