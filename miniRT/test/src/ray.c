/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:59:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/08 11:20:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point		at(double t, t_ray ray)
{
	t_point at;

	at = v_plus(ray.origin, v_multiply(ray.dir, t));
	return (at);
}

t_ray		ray(t_point orig, t_vec dir)
{
	t_ray ray;

	ray.origin = orig;
	ray.dir = dir;
	return (ray);
}