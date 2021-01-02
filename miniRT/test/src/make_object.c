/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:34:00 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/02 00:46:44 by hyeonkim         ###   ########.fr       */
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
	plane->n = normal;
	plane->color = color;
	return (plane);
}

t_triangle	*triangle(t_point a, t_point b, t_point c, t_color color)
{
	t_triangle	*triangle;
	t_vec		ab;

	if (!(triangle = (t_triangle *)malloc(sizeof(t_triangle))))
		return (0);
	triangle->p1 = a;
	triangle->p2 = b;
	triangle->p3 = c;
	triangle->n = v_normalize(v_cross(v_minus(b, a), v_minus(c, a)));
	triangle->color = color;
	return (triangle);
}

t_cylinder	*cylinder(t_point p, t_vec cen_vec, double diameter, double height, t_color color)
{
	t_cylinder	*cylinder;

	if (!(cylinder = (t_cylinder *)malloc(sizeof(t_cylinder))))
		return (0);
	cylinder->p = p;
	cylinder->center_vec = cen_vec;
	cylinder->color = color;
	cylinder->radius = diameter / 2;
	cylinder->len = height;
	return (cylinder);
}

t_square	*square(t_point p, t_vec normal, double side_len, t_color color)
{
	t_square		*square;
	
	if (!(square = (t_square *)malloc(sizeof(t_square))))
		return (0);
	square->p = p;
	square->n = v_normalize(normal);
	square->color = color;
	square->side_len = side_len;
	return (square);
}

t_cone		*cone(t_point p, double angle, t_vec axis, double h, t_color color)
{
	t_cone			*cone;

	if (!(cone = (t_cone *)malloc(sizeof(t_cone))))
		return (0);
	cone->p = p;
	cone->axis = v_normalize(axis);
	cone->angle = angle;
	cone->height = h;
	cone->color = color;
	return (cone);
}