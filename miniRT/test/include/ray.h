/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:59:05 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/08 11:20:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vector_utils.h"

typedef struct  s_ray
{
    t_point     origin;
    t_vec       dir;
}               t_ray;

t_point		    at(double t, t_ray ray);
t_ray	        ray(t_point orig, t_vec dir);

#endif