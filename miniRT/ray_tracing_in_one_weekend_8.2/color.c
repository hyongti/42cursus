/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:53:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 10:33:51 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_color	color(double x, double y, double z)
{
	t_color	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

void	write_color(t_color pixel_color, int samples_per_pixel)
{
	double	r;
	double	g;
	double	b;
	double	scale;

	scale = 1 / (double)samples_per_pixel;
	r = pixel_color.x * scale;
	g = pixel_color.y * scale;
	b = pixel_color.z * scale;

	
	printf("%d %d %d\n", (int)(256 * clamp(r, 0.0, 0.999)),
							(int)(256 * clamp(g, 0.0, 0.999)),
							(int)(256 * clamp(b, 0.0, 0.999)));
}