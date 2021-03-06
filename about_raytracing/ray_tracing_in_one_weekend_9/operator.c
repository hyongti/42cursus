/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:49:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/06 18:27:16 by root             ###   ########.fr       */
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

t_vec	v_multiply2(t_vec vec1, t_vec vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1);
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

t_vec		random_unit_vector(void)
{
	double	a;
	double	z;
	double	r;

	a = random_double2(0, 2 * PI);
	z = random_double2(-1, 1);
	r = sqrt(1 - z * z);
	return (vec(r * cos(a), r * sin(a), z));
}

t_vec		random_in_hemisphere(t_vec normal)
{
	t_vec	in_unit_sphere;
	
	in_unit_sphere = random_in_unit_sphere();
	if (v_dot(in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	else
		return(v_multiply(in_unit_sphere, -1));	
}

t_vec		reflect(t_vec v, t_vec n)
{
	return (v_minus(v, v_multiply(n, 2 * v_dot(v,n))));
}