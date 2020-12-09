/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:34:46 by root              #+#    #+#             */
/*   Updated: 2020/12/08 15:43:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include "vector_utils.h"

typedef struct	s_scene
{
	int			width;
	int			height;
	double		ratio;
}				t_scene;

typedef struct	s_cam
{
	double		v_height;
	double		v_width;
	double		focal_len;
	t_point		origin;
	t_vec		horizontal;
	t_vec		vertical;
	t_vec		focal;
	t_vec		lower_left_corner;
}				t_cam;

void	set_scene(t_scene *scene, int width, int height);
void	set_camera(t_cam *cam, t_scene scene);

#endif