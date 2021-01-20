/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 20:38:35 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

#include "vec.h"

typedef struct	s_sphere
{
    t_point		center;
	double		radius;
}				t_sphere;

t_sphere	*sphere(t_point center, double radius);


#endif