/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:50:05 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 16:32:50 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <random.h>
# include "rtweekend.h"

# define TRUE 1
# define FALSE 0

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef t_vec	t_point;
typedef t_vec	t_color;

void			input_elements(t_vec *vec, double x, double y, double z);
t_vec			vec(double x, double y, double z);
t_vec			v_plus(t_vec vec1, t_vec vec2);
t_vec			v_minus(t_vec vec1, t_vec vec2);
t_vec			v_multiply(t_vec vec1, double f);
t_vec			v_normalize(t_vec vec);
t_vec			v_cross(t_vec vec1, t_vec vec2);
double			v_dot(t_vec vec1, t_vec vec2);
double			v_length_squared(t_vec vec);
double			v_len(t_vec vec);
t_vec			random_vec(void);
t_vec			random_vec2(double min, double max);
t_vec			random_in_unit_sphere(void);
t_vec			random_unit_vector(void);
t_vec			random_in_hemisphere(t_vec normal);

#endif