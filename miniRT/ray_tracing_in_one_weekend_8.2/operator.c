/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:49:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 14:57:10 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	input_elements(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vec	vec(double x, double y, double z)
{
	t_vec	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
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

double	v_dot(t_vec vec1, t_vec vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

double	v_length_squared(t_vec vec)
{
	return(v_dot(vec, vec));
}

double	v_len(t_vec vec)
{
	return (sqrt(v_dot(vec, vec)));
}

t_vec	v_normalize(t_vec vec)
{
	t_vec	result;
	double	len;

	len = v_len(vec);
	input_elements(&result, vec.x / len, vec.y / len, vec.z / len);
	return (result);
}

t_vec	v_cross(t_vec vec1, t_vec vec2)
{
	t_vec	result;

	result.x = vec1.y * vec2.z - vec1.z * vec2.z;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (result);
}

t_vec		random_vec(void)
{
	return(vec(random_double(), random_double(), random_double()));
}

t_vec		random_vec2(double min, double max)
{
	return(vec(random_double2(min, max), random_double2(min, max), random_double2(min, max)));
}

t_vec		random_in_unit_sphere(void)
{
	t_vec	p;

	while (TRUE)
	{
		p = random_vec2(-1.0, 1.0);
		if (v_length_squared(p) >= 1)
		 	continue ;
		else
			return (p);
	}
}