/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyongti <hyongti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:08:37 by hyongti           #+#    #+#             */
/*   Updated: 2020/12/09 20:11:29 by hyongti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "vector_utils.h"

typedef struct	s_light
{
	t_point		point;
	t_color		color;
}				t_light;

t_light		*light(t_point poin, t_color color);

#endif