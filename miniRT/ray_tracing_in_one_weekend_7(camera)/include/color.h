/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:52:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 10:22:32 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include "vec.h"

double	clamp(double x, double min, double max);
void	write_color(t_color pixel_color, int samples_per_pixel);
t_color color(double x, double y, double z);

#endif