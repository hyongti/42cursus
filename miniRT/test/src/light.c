/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:11:05 by hyongti           #+#    #+#             */
/*   Updated: 2021/01/02 01:24:50 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light		*light(t_point point, double ratio, t_color color)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (0);
	light->p = point;
	light->brightness_ratio = ratio;
	light->color = color;
	return (light);
}