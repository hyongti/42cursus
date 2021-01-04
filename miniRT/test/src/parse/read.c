/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:35:09 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/03 14:57:59 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_scene		*read_rt(char *argv)
{	
	t_scene	*scene;
	int		fd;
	int		rd;
	int		i = 1;
	char	*line;

	if (!(scene = malloc(sizeof(t_scene))))
		exit(0);
	scene_init(scene);
	fd = open(argv, O_RDONLY);	
	rd = 1;
	while (rd == 1)
	{
		rd = get_next_line(fd, &line);
		parse_rt(line, scene);
		// free(line);
		// printf("%d번째 라인 : %s\n", i, line);
		i++;
	}
	// free(line);
	return (scene);
}

void	parse_rt(char *line, t_scene *scene)
{
	if (ft_strnstr(line, "R", 1) != NULL)
		get_resolution(line + 1, scene);
		// printf("info of R : %s\n", line + 1);
	else if (ft_strnstr(line, "A", 1) != NULL)
		get_ambient(line + 1, scene);
		// printf("info of A : %s\n", line + 1);
	else if (ft_strnstr(line, "c ", 2) != NULL)
		get_camera(line + 2, scene);
		// printf("info of c : %s\n", line + 1);
	else if (ft_strnstr(line, "l", 1) != NULL)
		get_light(line + 2, scene);
		// printf("info of l : %s\n", line + 1);
	else if (ft_strnstr(line, "sp", 2) != NULL)
		get_sphere(line + 2, scene);
		// printf("info of sp : %s\n", line + 2);
	else if (ft_strnstr(line, "cy", 2) != NULL)
		get_cylinder(line + 2, scene);
		// printf("info of cy : %s\n", line + 2);
	else if (ft_strnstr(line, "sq", 2) != NULL)
		get_square(line + 2, scene);
		// printf("info of sq : %s\n", line + 2);
	else if (ft_strnstr(line, "pl", 2) != NULL)
		get_plane(line + 2, scene);
		// printf("info of pl : %s\n", line + 2);
	else if (ft_strnstr(line, "tr", 2) != NULL)
		get_triangle(line + 2, scene);
		// printf("info of tr : %s\n", line + 2);
}