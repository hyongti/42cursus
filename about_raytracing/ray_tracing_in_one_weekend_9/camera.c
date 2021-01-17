/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:45:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 11:08:22 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	set_camera(t_camera *cam, double ratio)
{
	cam->origin = vec(0, 0, 0);
	cam->viewport_height = 2.0;
	cam->viewport_width = ratio * cam->viewport_height;
	cam->focal_length = 1.0;
	cam->horizontal = vec(cam->viewport_width, 0, 0);
	cam->vertical = vec(0, cam->viewport_height, 0);
	cam->focal = vec(0, 0, cam->focal_length);
	cam->lower_left_corner = v_minus(v_minus(v_minus(cam->origin,
								v_multiply(cam->horizontal, 0.5)),
								v_multiply(cam->vertical, 0.5)), cam->focal);
}