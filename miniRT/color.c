/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:31:33 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/01 20:20:37 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"



void	write_color(t_vec vec)
{
	t_vec	to_print;

	to_print = v_multiply(vec, 255.999);
	printf("%d %d %d\n", (int)to_print.x, (int)to_print.y, (int)to_print.z);
}