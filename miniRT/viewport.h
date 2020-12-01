/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:19:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/01 20:22:24 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H

#include "vec.h"

typedef struct	s_pixels
{
	double		ratio;
	int			width;
	int			height;
}				t_pixels;

typedef struct	s_viewport
{
	double		width;
	double		height;
	double		focal;
}				t_viewport;

typedef struct	s_ray
{
	t_vec		horizontal;
	t_vec		vertical;
	t_vec		focal;
}				t_ray;

typedef struct	s_idx
{
	int			i;
	int			j;
	double		u;
	double		v;
}				t_idx;

void			set_pixels(t_pixels *pixel, double ratio, int width);
void			set_base_ray(t_ray *base, t_viewport viewport);
t_vec			get_llc(t_vec origin, t_ray base);
t_vec			get_ray(t_vec lower_left_corner, t_ray base, t_idx idx, t_vec origin);

#endif