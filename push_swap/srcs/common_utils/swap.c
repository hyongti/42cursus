/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:23:38 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/23 19:31:45 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	write(1, "sa\n", 3);
	swap_stack(stack_a);
}

void	sb(t_list **stack_b)
{
	write(1, "sb\n", 3);
	swap_stack(stack_b);
}

void	swap(t_list **stack_a, t_list **stack_b, char *line)
{
	if (line[0] == 's')
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
	else if (line[0] == 'a')
		swap_stack(stack_a);
	else if (line[0] == 'b')
		swap_stack(stack_b);
	else
		write(1, "Wrong Command\n", 14);
}

void	swap_stack(t_list **stack)
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
