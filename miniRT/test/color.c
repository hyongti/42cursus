/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:53:16 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 17:14:24 by hyeonkim         ###   ########.fr       */
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

void	write_color(t_vec vec)
{
	printf("%d %d %d\n", (int)(vec.x * 255.999), (int)(vec.y * 255.999), (int)(vec.z * 255.999));
}