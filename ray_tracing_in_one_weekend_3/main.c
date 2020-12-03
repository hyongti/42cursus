/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 09:36:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ray.h"
#include "color.h"

int			main()
{
	// Image
	int			image_width = 256;
	int			image_height = 256;

	//Render
	int			i;
	int			j = image_height - 1;
	double		u;
	double		v;
	t_ray		r;
	t_color		pixel_color;

	printf("P3\n%d %d\n255\n", image_width, image_height);
	while (j >= 0)
	{
		i = 0;
		while (i < image_width)
		{
			pixel_color = color((double)i / (image_width - 1), (double)j / (image_height - 1), 0.25);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
}