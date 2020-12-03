/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:59:05 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 15:23:37 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "vec.h"

typedef struct  s_ray
{
    t_point     origin;
    t_vec       dir;
}               t_ray;

t_point		    at(double t, t_ray ray);
t_ray	        ray(t_point orig, t_vec dir);

#endif