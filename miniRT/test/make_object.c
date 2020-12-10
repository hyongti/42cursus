/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:34:00 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/09 21:17:07 by hyongti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_object.h"

t_sphere	*sphere(t_point center, double radius, t_color color)
{
	t_sphere	*sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (0);
	sphere->center = center;
	sphere->radius = radius;
	sphere->color = color;
	return (sphere);
}

t_plane		*plane(t_point point, t_vec normal, t_color color)
{
	t_plane		*plane;

	if (!(plane = (t_plane *)malloc(sizeof(t_plane))))
		return (0);
	plane->point = point;
	plane->normal = normal;
	plane->color = color;
	return (plane);
}

t_triangle	*triangle(t_point a, t_point b, t_point c, t_color color)
{
	t_triangle	*triangle;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return (0);
	triangle->p1 = a;
	triangle->p2 = b;
	triangle->p3 = c;
	triangle->color = color;
	return (triangle);
}