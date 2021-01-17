/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:42:55 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 11:03:35 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec.h"

typedef struct	s_camera
{
	double		viewport_height;
	double		viewport_width;
	double		focal_length;
	t_point		origin;
	t_vec		horizontal;
	t_vec		vertical;
	t_vec		focal;
	t_vec		lower_left_corner;
}				t_camera;

void	set_camera(t_camera *cam, double ratio);

#endif