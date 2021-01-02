/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/02 00:57:15 by hyeonkim         ###   ########.fr       */
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
	t_vec		n;
	t_color		color;
}				t_plane;

typedef struct	s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_vec		n;
	t_color		color;
}				t_triangle;

typedef struct	s_cylinder
{
	t_point		p;
	t_vec		center_vec;
	t_color		color;
	double		radius;
	double		len;
}				t_cylinder;

typedef struct	s_square
{
	t_point		p;
	t_vec		n;
	t_color		color;
	double		side_len;
}				t_square;

typedef	struct	s_cone
{
	t_point		p;
	t_color		color;
	t_vec		axis;
	double		height;
	double		angle;
}				t_cone;

t_sphere	*sphere(t_point center, double radius, t_color color);
t_plane		*plane(t_point point, t_vec normal, t_color);
t_triangle	*triangle(t_point p1, t_point p2, t_point p3, t_color color);
t_cylinder	*cylinder(t_point p, t_vec cen_vec, double diameter, double height, t_color color);
t_plane		*plane(t_point p, t_vec normal, t_color color);
t_square	*square(t_point p, t_vec normal, double side_len, t_color color);
t_cone		*cone(t_point p, double angle, t_vec axis, double h, t_color color);

#endif