/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42uym <42uym@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 09:18:14 by 42uym             #+#    #+#             */
/*   Updated: 2020/12/30 00:31:43 by 42uym            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

t_vec	reflect(t_vec v, t_vec n)
{
	return (v_minus(v, v_multiply(n ,v_dot(v, n) * 2)));
}

void		set_face_normal(t_ray r, t_hit_record *rec)
{
	if (v_dot(r.dir, rec->normal) < 0)
		rec->front_face = TRUE;
	else
	{
		rec->normal = v_multiply(rec->normal, -1);
		rec->front_face = FALSE;
	}
}

int			is_inside(t_point p1, t_point p2, t_point p3, t_point p)
{
	t_vec	v1;
	t_vec	v2;

	v1 = v_cross(v_minus(p2, p1), v_minus(p, p1));
	v2 = v_cross(v_minus(p2, p1), v_minus(p3, p1));
	if (v_dot(v1, v2) < 0)
		return (0);
	v1 = v_cross(v_minus(p3, p1), v_minus(p, p1));
	v2 = v_cross(v_minus(p3, p1), v_minus(p2, p1));
	if (v_dot(v1, v2) < 0)
		return (0);
	v1 = v_cross(v_minus(p2, p3), v_minus(p, p3));
	v2 = v_cross(v_minus(p2, p3), v_minus(p1, p3));
	if (v_dot(v1, v2) < 0)
		return (0);
	return (1);
}