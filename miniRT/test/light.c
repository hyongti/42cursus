/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:11:05 by hyongti           #+#    #+#             */
/*   Updated: 2020/12/09 20:13:10 by hyongti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

t_light		*light(t_point point, t_color color)
{
	t_light	*light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (0);
	light->point = point;
	light->color = color;
	return (light);
}