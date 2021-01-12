/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_translate3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 20:44:36 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/11 17:15:28 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

static void	pyramid_z_move(int keycode, t_cntl *cntl)
{
	int	i;
	int	j;

	i = -1;
	if (keycode == KEY_W)
	{
		while (++i < 4)
		{	
			j = -1;
			while (++j < 3)
				((t_pyramid *)(cntl->selected->object))->tr[i]->p[j].z -= 0.3;
		}
		((t_pyramid *)(cntl->selected->object))->sq->p.z -= 0.3;
		((t_pyramid *)(cntl->selected->object))->p.z -= 0.3;
	}
	if (keycode == KEY_S)
	{
		while (++i < 4)
		{	
			j = -1;
			while (++j < 3)
				((t_pyramid *)(cntl->selected->object))->tr[i]->p[j].z += 0.3;
		}
		((t_pyramid *)(cntl->selected->object))->sq->p.z += 0.3;
		((t_pyramid *)(cntl->selected->object))->p.z += 0.3;
	}
}

static void	pyramid_x_move(int keycode, t_cntl *cntl)
{
	int	i;
	int	j;

	i = -1;
	if (keycode == KEY_A)
	{
		while (++i < 4)
		{	
			j = -1;
			while (++j < 3)
				((t_pyramid *)(cntl->selected->object))->tr[i]->p[j].x -= 0.3;
		}
		((t_pyramid *)(cntl->selected->object))->sq->p.x -= 0.3;
		((t_pyramid *)(cntl->selected->object))->p.x -= 0.3;
	}
	if (keycode == KEY_D)
	{
		while (++i < 4)
		{	
			j = -1;
			while (++j < 3)
				((t_pyramid *)(cntl->selected->object))->tr[i]->p[j].x += 0.3;
		}
		((t_pyramid *)(cntl->selected->object))->sq->p.x += 0.3;
		((t_pyramid *)(cntl->selected->object))->p.x += 0.3;
	}
}

static void	pyramid_y_move(int keycode, t_cntl *cntl)
{
	int	i;
	int	j;

	i = -1;
	if (keycode == KEY_Q)
	{
		while (++i < 4)
		{	
			j = -1;
			while (++j < 3)
				((t_pyramid *)(cntl->selected->object))->tr[i]->p[j].y -= 0.3;
		}
		((t_pyramid *)(cntl->selected->object))->sq->p.y -= 0.3;
		((t_pyramid *)(cntl->selected->object))->p.y -= 0.3;
	}
	if (keycode == KEY_E)
	{
		while (++i < 4)
		{	
			j = -1;
			while (++j < 3)
				((t_pyramid *)(cntl->selected->object))->tr[i]->p[j].y += 0.3;
		}
		((t_pyramid *)(cntl->selected->object))->sq->p.y += 0.3;
		((t_pyramid *)(cntl->selected->object))->p.y += 0.3;
	}
}

void		translate_pyramid(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_W || keycode == KEY_S)
		pyramid_z_move(keycode, cntl);
	else if (keycode == KEY_A || keycode == KEY_D)
		pyramid_x_move(keycode, cntl);
	else if (keycode == KEY_Q || keycode == KEY_E)
		pyramid_y_move(keycode, cntl);
}