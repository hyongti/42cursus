/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:53:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/04 15:42:57 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color(double x, double y, double z)
{
	t_color	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

int		color_to_int(t_color pixel_color)
{
	int			r;
	int			g;
	int			b;

	r = (int)(255.999 * pixel_color.x);
	g = (int)(255.999 * pixel_color.y);
	b = (int)(255.999 * pixel_color.z);
	return ((r << 16) + (g << 8) + b);
}

// void	write_color(t_vec vec)
// {
// 	printf("%d %d %d\n", (int)(vec.x * 255.999), (int)(vec.y * 255.999), (int)(vec.z * 255.999));
// }