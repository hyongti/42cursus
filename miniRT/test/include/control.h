/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:48:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/05 17:33:09 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

#include "scene.h"
#include "hit.h"
#include "mlx.h"

# define DEFM 0
# define OBJM 1
# define CAMM 2
# define LIGM 3

# define LIGHT_ON 1
# define LIGHT_OFF 0

typedef	struct	s_cntl
{
	void		*mlx;
	void		*win;
	t_scene		*scene;
	t_objects	*selected;
	t_data		*img;
	// t_data		img;
	int			mode; // 0:default 1:object transform 2:camera transform
	int			light_on;
}				t_cntl;

void		cntl_init(t_cntl *cntl);
void		cntl_display_resolution(t_cntl *cntl);
int			cntl_click_x(void);//int focus, t_cntl *cntl);
void		my_mlx_control(t_cntl *cntl);
int			cntl_close(void);
int			cntl_mouse_click(int button, int x, int y, t_cntl *cntl);

/*
**	object control
*/

void		cntl_object_translate_x_pos(t_cntl *cntl);
void		cntl_object_translate_y_pos(t_cntl *cntl);
void		cntl_object_scale(t_cntl *cntl);
void		cntl_object_deselect(t_cntl *cntl);
void		cntl_object_select(int button, int x, int y, t_cntl *cntl);
void		cntl_object(int keycode, t_cntl *cntl);

/*
**	light control
*/

void		cntl_light_mode_on(t_cntl *cntl);
void		cntl_light_mode_off(t_cntl *cntl);
void		cntl_light_select(t_cntl *cntl);
void		cntl_light_on_and_off(t_cntl *cntl);
void		cntl_light_translate_x_pos(t_cntl *cntl);
void		cntl_light_translate_y_pos(t_cntl *cntl);
void		cntl_light_bright_up(t_cntl *cntl);
void		cntl_light_bright_down(t_cntl *cntl);
void		cntl_light(t_cntl *cntl, int keycode);

/*
**	camera control
*/

void		cntl_camera_on(t_cntl *cntl);
void		cntl_camera_off(t_cntl *cntl);
void		cntl_select_camera(t_cntl *cntl);
void		cntl_camera_translate(int keycode, t_cntl *cntl);
void		cntl_camera_hfov(int keycode, t_cntl *cntl);
void		cntl_camera(t_cntl *cntl, int keycode);

# endif