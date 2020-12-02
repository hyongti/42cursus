/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:34:00 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 20:49:35 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

double		hit_sphere(t_point center, double radius, t_ray r)
{
	t_vec	oc = v_minus(r.origin, center);
	double	a = v_dot(r.dir, r.dir);
	double	b = v_dot(oc, r.dir);
	double	c = v_dot(oc, oc) - radius * radius;
	double	discriminant = b * b - a * c;
	printf("%f %f %f\n", a, b, c);
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / a);
}
