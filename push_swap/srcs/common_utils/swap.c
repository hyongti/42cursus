/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:23:38 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 17:24:39 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int		*tmp;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		tmp = (*stack)->content;
		(*stack)->content = ((*stack)->next)->content;
		((*stack)->next)->content = tmp;
	}
	else
		printf("not enough numbers\n");
}
