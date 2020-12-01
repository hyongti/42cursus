/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:07:27 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/11/30 19:32:36 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

void	input_elements(t_vec *vec, double x, double y, double z);
t_vec	v_plus(t_vec vec1, t_vec vec2);
t_vec	v_minus(t_vec vec1, t_vec vec2);
t_vec	v_multiply(t_vec vec1, double f);
t_vec	v_normalize(t_vec vec);
t_vec	v_cross(t_vec vec1, t_vec vec2);
double	v_dot(t_vec vec1, t_vec vec2);
double	v_len(t_vec vec);

#endif
