/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:08:37 by hyongti           #+#    #+#             */
/*   Updated: 2021/01/05 17:01:10 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "vector_utils.h"

typedef struct	s_light
{
	t_point		p;
	t_color		color;
	double		brightness;
}				t_light;

t_light		*light(t_point point, double ratio, t_color color);

#endif