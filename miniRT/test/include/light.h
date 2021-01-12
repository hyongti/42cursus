/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 20:08:37 by hyongti           #+#    #+#             */
/*   Updated: 2021/01/06 23:00:38 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "utils.h"

t_spot_light		*spot_light(t_point point, double ratio, t_color color);
t_parallel_light	*parallel_light(t_vec dir, t_color color);

#endif