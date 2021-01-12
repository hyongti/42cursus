/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:25:32 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/12 21:34:14 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_color	checkerboard(t_hit_record *rec)
{
	double		sines;

	sines = sin(50 * rec->u) * sin(50 * rec->v);
	if (sines < 0)
		return (color(0.8, 0.8, 0.8));
	else
		return (rec->texture->albedo);
}

t_color	rainbow(t_hit_record *rec)
{
	t_color		result;

	result = v_multiply(v_plus(rec->normal, vec(1.0, 1.0, 1.0)), 0.5);
	return (result);
}

t_color	wave(t_hit_record *rec)
{
	t_color		wave;
	double		disrupt;
	double		interval;

	interval = 10;
	wave = rec->texture->albedo;
	disrupt = (sin(rec->p.x * interval) + 1) * 0.5;
	wave.x = wave.x * disrupt;
	disrupt = (sin(rec->p.y * interval) + 1) * 0.5;
	wave.y = wave.y * disrupt;
	disrupt = (sin(rec->p.z * interval) + 1) * 0.5;
	wave.z = wave.z * disrupt;
	return (wave);
}