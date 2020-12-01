/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:56:31 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/01 18:07:19 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

int			hit_sphere(t_vec origin, t_vec dir, t_sphere sphere, t_record *rec)
{
	t_vec		oc;
	t_vec		ray;
	double		a;
	double		b;
	double		c;
	double		root;
	double		discriminant;

	ray = v_plus(origin, dir);
	oc = v_minus(origin, sphere.center);
	a = v_dot(ray, ray);
	b = v_dot(oc, ray);
	c = v_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = b * b - a * c;
	if (discriminant < 0)
	 	return (0);
	else
	{
		root = (-b - sqrt(discriminant)) / a;
		if (root < T_MIN || root > T_MAX)
			return (0);
	}
	rec->t = root;
	rec->p = v_multiply(v_plus(origin, dir), rec->t);
	rec->normal = v_multiply(v_minus(rec->p, sphere.center), 1 / sphere.radius);
	set_face_normal(&ray, rec);
	return (1);
}