/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_scale.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 22:11:44 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/11 12:17:04 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_object_scale(int keycode, t_cntl *cntl)
{
	if (cntl->selected->type == SP)
		scale_sphere(keycode, cntl);
	else if (cntl->selected->type == SQ)
		scale_square(keycode, cntl);
	else if (cntl->selected->type == CY)
		scale_cylinder(keycode, cntl);
	else if (cntl->selected->type == CO)
		scale_cone(keycode, cntl);
	else if (cntl->selected->type == CU)
		scale_cube(keycode, cntl);
	else if (cntl->selected->type == PY)
		scale_pyramid(keycode, cntl);
}

void		scale_sphere(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
		((t_sphere *)cntl->selected->object)->radius += 0.25;
	else if (keycode == KEY_AR_D)
		((t_sphere *)cntl->selected->object)->radius -= 0.25;
}

void		scale_square(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
		((t_square *)cntl->selected->object)->side_len += 0.25;
	else if (keycode == KEY_AR_D)
		((t_square *)cntl->selected->object)->side_len -= 0.25;
}

void		scale_cylinder(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
	{
		((t_cylinder *)cntl->selected->object)->radius += 0.25;
		((t_cylinder *)cntl->selected->object)->len += 0.25;
	}
	else if (keycode == KEY_AR_D)
	{
		((t_cylinder *)cntl->selected->object)->radius -= 0.25;
		((t_cylinder *)cntl->selected->object)->len -= 0.25;
	}
}

void		scale_cone(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_AR_U)
		((t_cone *)cntl->selected->object)->height += 0.25;
	else if (keycode == KEY_AR_D)
		((t_cone *)cntl->selected->object)->height -= 0.25;
}

void		scale_cube(int keycode, t_cntl *cntl)
{
	double	scale;
	t_cube	*temp;

	scale = (keycode == KEY_AR_U) ? 0.25 : -0.25;
	printf("%f\n", ((t_cube *)cntl->selected->object)->len);
	temp = cube(((t_cube *)cntl->selected->object)->p,
				((t_cube *)cntl->selected->object)->len + scale);
	free(cntl->selected->object);
	cntl->selected->object = temp;
}

void		scale_pyramid(int keycode, t_cntl *cntl)
{
	double		scale;
	t_pyramid	*temp;

	scale = (keycode == KEY_AR_U) ? 0.25 : -0.25;
	temp = pyramid(((t_pyramid *)cntl->selected->object)->p,
		((t_pyramid *)cntl->selected->object)->len + scale);
	free(cntl->selected->object);
	cntl->selected->object = temp;
}