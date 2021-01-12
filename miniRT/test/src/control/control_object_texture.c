/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_object_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 21:22:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/12 21:37:46 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void		cntl_object_texture(int keycode, t_cntl *cntl)
{
	if (keycode == KEY_Z)
	{	
		cntl->selected->texture->type = CHECK;
		printf("TEXTURE : CHECKERBOARD\n");
	}
	else if (keycode == KEY_X)
	{
		cntl->selected->texture->type = RAINBOW;
		printf("TEXTURE : RAINBOW\n");
	}
	else if (keycode == KEY_C)
	{
		cntl->selected->texture->type = WAVE;
		printf("TEXTURE : WAVE\n");
	}
	else if (keycode == KEY_V)
	{
		cntl->selected->texture->type = DEFAULT;
		printf("TEXTURE : DEFAULT\n");
	}
}