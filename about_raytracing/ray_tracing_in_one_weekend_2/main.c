/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 09:40:16 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			main()
{
	// Image
	int			image_width = 256;
	int			image_height = 256;

	//Render
	int			i;
	int			j = image_height - 1;
	double		r;
	double		g;
	double		b;
	int			ir;
	int			ig;
	int			ib;

	printf("P3\n%d %d\n255\n", image_width, image_height);
	while (j >= 0)
	{
		i = 0;
		while (i < image_width)
		{
			r = (double)i / (image_width - 1);
			g = (double)j / (image_height - 1);
			b = 0.25;

			ir = (int)(r * 255.999);
			ig = (int)(g * 255.999);
			ib = (int)(b * 255.999);

			printf("%d %d %d\n", ir, ig, ib);
			++i;
		}
		--j;
	}
}