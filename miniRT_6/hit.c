/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:20:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 20:48:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"
#include "sphere.h"

t_color		ray_color(t_ray r)
{
	double			t;
	t_vec			unit_direction;
	t_point			center;
	t_vec			normal;

	input_elements(&center, 0, 0, -1);
	t = hit_sphere(center, 0.5, r);
	if (t > 0.0)
	{
		normal = v_normalize(v_minus(at(t, r), center));
		return (v_multiply(color(normal.x + 1, normal.y + 1, normal.z + 1), 0.5));
	}
	unit_direction = v_normalize(r.dir);
	t = 0.5 * (unit_direction.y + 1.0);
	return (v_plus(v_multiply(color(1.0, 1.0, 1.0), (1.0 - t)), v_multiply(color(0.5, 0.7, 1.0), t)));
}
