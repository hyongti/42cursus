/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:59:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 11:02:54 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_point		point(double x, double y, double z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

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

t_ray		get_ray(t_camera cam, double u, double v)
{
	t_ray	result;

	result = ray(cam.origin, v_minus(v_plus(v_plus(cam.lower_left_corner, 
				v_multiply(cam.horizontal, u)), v_multiply(cam.vertical, v)), cam.origin));
	return (result);
}