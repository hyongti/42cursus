/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:17 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/11 15:36:55 by root             ###   ########.fr       */
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

typedef struct	s_cylinder
{
	t_point		p;
	t_vec		center_vec;
	t_color		color;
	double		radius;
	double		len;
}				t_cylinder;


t_sphere	*sphere(t_point center, double radius, t_color color);
t_plane		*plane(t_point point, t_vec normal, t_color);
t_triangle	*triangle(t_point p1, t_point p2, t_point p3, t_color color);
t_cylinder	*cylinder(t_point p, t_vec cen_vec, t_color color, double radius, double len);

#endif