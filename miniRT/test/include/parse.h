/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:36:28 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/11 20:28:53 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include <fcntl.h>
#include "utils.h"
#include "scene.h"
#include "mlx.h"

/*
** parsing
*/

t_scene	*read_rt(char *argv, void *mlx);
void	parse_rt(char *line, t_scene *scene, void *mlx);
void	get_resolution(char *line, t_scene *scene);
void	get_ambient(char *line, t_scene *scene);
void	get_background(char *line, t_scene *scene, void *mlx);
void	get_parallel_light(char *line, t_scene *scene);
void	get_camera(char *line, t_scene *scene);
void	get_light(char *line, t_scene *scene);
void	get_sphere(char *line, t_scene *scene);
void	get_cylinder(char *line, t_scene *scene);
void	get_square(char *line, t_scene *scene);
void	get_plane(char *line, t_scene *scene);
void	get_triangle(char *line, t_scene *scene);
void	get_cone(char *line, t_scene *scene);
void	get_cube(char *line, t_scene *scene);
void	get_pyramid(char *line, t_scene *scene);

/*
**  error
*/

int		is_aligned(t_vec vec);
void	error_not_aligned(void);
void	malloc_error(void);
void	parse_error(void);

# endif