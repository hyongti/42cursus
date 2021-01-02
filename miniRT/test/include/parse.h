/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:36:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/01 21:37:04 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <fcntl.h>
#include "scene.h"
#include "color.h"
#include "../libft/get_next_line.h"

t_scene	*read_rt(char *argv);
void	parse_rt(char *line, t_scene *scene);
void	get_resolution(char *line, t_scene *scene);
void	get_ambient(char *line, t_scene *scene);
void	get_camera(char *line, t_scene *scene);
void	get_light(char *line, t_scene *scene);
void	get_sphere(char *line, t_scene *scene);
void	get_cylinder(char *line, t_scene *scene);
void	get_square(char *line, t_scene *scene);
void	get_plane(char *line, t_scene *scene);
void	get_triangle(char *line, t_scene *scene);

# endif