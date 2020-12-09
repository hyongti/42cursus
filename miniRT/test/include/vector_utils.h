/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:50:05 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/08 20:11:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_UTILS_H
# define VECTOR_UTILS_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef t_vec	t_point;
typedef t_vec	t_color;

t_point	point(double x, double y, double z);
t_vec	vec(double x, double y, double z);
void	input_elements(t_vec *vec, double x, double y, double z);
t_vec	v_plus(t_vec vec1, t_vec vec2);
t_vec	v_minus(t_vec vec1, t_vec vec2);
t_vec	v_multiply(t_vec vec1, double f);
t_vec	v_multiply_2(t_vec vec1, t_vec vec2);
t_vec	v_normalize(t_vec vec);
t_vec	v_cross(t_vec vec1, t_vec vec2);
double	v_dot(t_vec vec1, t_vec vec2);
double	v_len(t_vec vec);

#endif