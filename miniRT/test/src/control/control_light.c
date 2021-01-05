/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:04:45 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/05 17:06:54 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	cntl_light_mode_on(t_cntl *cntl)
{
	cntl->mode = LIGM;
	if (cntl->selected == 0)
	{
		while (cntl->scene->objs->type != LIGHT)
			cntl->scene->objs = cntl->scene->objs->next;
		cntl->selected = cntl->scene->objs;
	}
	printf("< light mode >\n[right arrow] key : next light\n");
}

void	cntl_light_on_and_off(t_cntl *cntl)
{
	if (cntl->light_on == LIGHT_OFF)
	{
		cntl->light_on = LIGHT_ON;
		printf("light on(if you press spacebar, light off)\n");
	}
	else
	{
		cntl->light_on = LIGHT_OFF;
		printf("light off(if you press spacebar, light on)\n");
	}
	render_preview(cntl->scene, cntl->img, cntl->light_on);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}

void	cntl_light_select(t_cntl *cntl)
{
	t_objects	*temp;

	if (cntl->selected == 0 || cntl->selected->next == 0)  
		temp = (t_objects *)cntl->scene->objs;
	else
		temp = (t_objects *)cntl->selected->next;
	while (temp && temp->type != LIGHT)
		temp = temp->next;
	if (temp == 0)
	{
		temp = (t_objects *)cntl->scene->objs;
		while (temp && temp->type != LIGHT)
			temp = temp->next;
		cntl->selected = temp;
		printf("마지막 조명입니다.\n");
	}
	else
	{
		cntl->selected = temp;
		printf("다음 조명입니다.\n");
	}
}

void	cntl_light_mode_off(t_cntl *cntl)
{
	printf("light deselect\n");
	cntl->selected = NULL;
	cntl->mode = DEFM;
}

void	cntl_light_bright_up(t_cntl *cntl)
{
	double		brightness;
	t_color 	*light_color;

	brightness = ((t_light *)(cntl->selected->object))->brightness;
	light_color = &((t_light *)(cntl->selected->object))->color;
	if (cntl->selected->type == LIGHT)
	{
		((t_light *)(cntl->selected->object))->brightness += 0.1;
		if (((t_light *)(cntl->selected->object))->brightness > 1)
			((t_light *)(cntl->selected->object))->brightness = 1;
		*light_color = v_multiply(*light_color, 1.0 / brightness);
		brightness = ((t_light *)(cntl->selected->object))->brightness;
		*light_color = v_multiply(*light_color, brightness);
	}
	printf("조명증가\n");
}

void	cntl_light_bright_down(t_cntl *cntl)
{
	double		brightness;
	t_color	*light_color;

	brightness = ((t_light *)(cntl->selected->object))->brightness;
	light_color = &((t_light *)(cntl->selected->object))->color;
	if (cntl->selected->type == LIGHT)
	{
		((t_light *)(cntl->selected->object))->brightness -= 0.1;
		if (((t_light *)(cntl->selected->object))->brightness <= 0)
			((t_light *)(cntl->selected->object))->brightness = 0.000001;
		*light_color = v_multiply(*light_color, 1.0 / brightness);
		brightness = ((t_light *)(cntl->selected->object))->brightness;
		*light_color = v_multiply(*light_color, brightness);
	}
	printf("조명감소\n");
}

void	cntl_light_translate_x_pos(t_cntl *cntl)
{
	if (cntl->selected->type == LIGHT)
		((t_light *)(cntl->selected->object))->p.x += 0.3;
	printf("라이트 x이동\n");
}

void	cntl_light_translate_y_pos(t_cntl *cntl)
{
	if (cntl->selected->type == LIGHT)
		((t_light *)(cntl->selected->object))->p.y += 0.3;
	printf("라이트 y이동\n");
}

void	cntl_light(t_cntl *cntl, int keycode)
{
	if (keycode == 124) // 광원 바꾸기. 오른쪽 방향키
		cntl_light_select(cntl);
	else if (keycode == 7) // 광원 이동 x
		cntl_light_translate_x_pos(cntl);
	else if (keycode == 9) // 광원 이동 v
		cntl_light_translate_y_pos(cntl);
	else if (keycode == 53) // 선택 종료 esc
		cntl_light_mode_off(cntl);
	else if (keycode == 24) // 밝기 밝게 =
		cntl_light_bright_up(cntl);
	else if (keycode == 27) // 밝기 어둡게 -
		cntl_light_bright_down(cntl);
	render_preview(cntl->scene, cntl->img, cntl->light_on);
	mlx_put_image_to_window(cntl->mlx, cntl->win, cntl->img->img, 0, 0);
}