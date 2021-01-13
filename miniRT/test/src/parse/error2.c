/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:54:35 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/13 16:09:28 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void		range_error(void)
{
	printf("ALBEDO VALUE MUST BE IN RANGE[0, 255]\n");
	printf("EXIT PROGRAM\n");
	exit(0);
}

int			albedo_range_check(char **data)
{
	double	r;
	double	g;
	double	b;

	r = ft_atod(data[0]);
	g = ft_atod(data[1]);
	b = ft_atod(data[2]);
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}
