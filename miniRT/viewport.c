/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:20:25 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/01 20:12:51 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

void			set_base_ray(t_ray *base, t_viewport viewport)
{
	input_elements(&base->horizontal, viewport.width, 0, 0);
	input_elements(&base->vertical, 0, viewport.height, 0);
	input_elements(&base->focal, 0, 0, viewport.focal);
}

void			set_pixels(t_pixels *pixel, double ratio, int width)
{
	pixel->ratio = ratio;
	pixel->width = width;
	pixel->height = (int)(width / ratio);
}

// void			set_viewport()

t_vec			get_llc(t_vec origin, t_ray base)
{
	t_vec		result;

	result = v_minus(v_minus(v_minus(origin,
			v_multiply(base.horizontal, 0.5)),
			v_multiply(base.vertical, 0.5)), base.focal);
	return (result);
}

t_vec			get_ray(t_vec llc, t_ray base, t_idx idx, t_vec origin)
{
	t_vec		result;

	result = v_minus(v_plus(llc, v_plus(v_multiply(base.horizontal, idx.u),
			v_multiply(base.vertical, idx.v))), origin);
	return (result);
}
