/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:10:54 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/11 20:29:35 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	error_not_aligned(void)
{
	printf("VECTOR IS NOT AXIS-ALIGNED\n");
	exit(0);
}

void	malloc_error(void)
{
	printf("MEMORY ALLOCATION FAILED\n");
	printf("EXIT PROGRAM\n");
	exit(0);
}

void	parse_error(void)
{
	printf("WRONG DATA FORMAT\n");
	printf("EXIT PROGRAM\n");
	exit(0);
}