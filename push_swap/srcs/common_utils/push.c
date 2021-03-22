/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:23:38 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/22 12:44:06 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_a, t_list **stack_b, char *line)
{
	if (line[0] == 'b')
		push_stack1_to_stack2(stack_a, stack_b);
	else if (line[0] == 'a')
		push_stack1_to_stack2(stack_b, stack_a);
	else
		write(1, "Wrong Command\n", 14);
}

void	push_stack1_to_stack2(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	tmp = *stack1;
	if (*stack1 == NULL)
		printf("stack is empty\n");
	else
	{
		*stack1 = (*stack1)->next;
		ft_lstadd_front(stack2, tmp);
	}
}
