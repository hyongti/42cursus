/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_transform_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:15:46 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/11/29 15:28:52 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	input_elements(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vec	v_plus(t_vec vec1, t_vec vec2)
{
	t_vec	result;

	input_elements(&result, vec1.x + vec2.x,
							vec1.y + vec2.y,
							vec1.z + vec2.z);
	return (result);
}

t_vec	v_minus(t_vec vec1, t_vec vec2)
{
	t_vec	result;

	input_elements(&result, vec1.x - vec2.x,
							vec1.y - vec2.y,
							vec1.z - vec2.z);
	return (result);
}

t_vec	v_multiply(t_vec vec1, double f)
{
	t_vec	result;

	input_elements(&result, vec1.x * f,
							vec1.y * f,
							vec1.z * f);
	return (result);
}

t_vec	origin_direction(t_vec origin, t_vec direction)
{
	t_vec	result;

	result = v_plus(origin, direction);
	return (result);
}