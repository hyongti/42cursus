/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:23:38 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/23 19:31:07 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	write(1, "ra\n", 3);
	rotate_stack(stack_a);
}

void	rb(t_list **stack_b)
{
	write(1, "rb\n", 3);
	rotate_stack(stack_b);
}

void	rotate(t_list **stack_a, t_list **stack_b, char *line)
{
	if (line[0] == 'r')
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
	}
	else if (line[0] == 'a')
		rotate_stack(stack_a);
	else if (line[0] == 'b')
		rotate_stack(stack_b);
	else
		write(1, "Wrong Command\n", 14);
}

void	rotate_stack(t_list **stack)
{
	t_list	*tmp;

	if (*stack != NULL && ft_lstlast(*stack) != NULL)
	{
		tmp = *stack;
		ft_lstadd_back(stack, ft_lstnew((*stack)->content));
		*stack = (*stack)->next;
		tmp->next = NULL;
		// free(tmp);
	}
	else
		printf("not enough numbers\n");
}
