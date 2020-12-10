/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/09 21:16:37 by hyongti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_OBJECT_H
# define MAKE_OBJECT_H

#include "vector_utils.h"

typedef struct	s_sphere
{
	t_point		center;
	double		radius;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_point		point;
	t_vec		normal;
	t_color		color;
}				t_plane;

typedef struct	s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_color		color;
}				t_triangle;


t_sphere	*sphere(t_point center, double radius, t_color color);
t_plane		*plane(t_point point, t_vec normal, t_color);
t_triangle	*triangle(t_point p1, t_point p2, t_point p3, t_color color);

#endif