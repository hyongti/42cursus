/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:59:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 15:23:18 by hyeonkim         ###   ########.fr       */
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