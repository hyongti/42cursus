/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:24:10 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/23 19:30:31 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	write(1, "rra\n", 4);
	reverse_rotate_stack(stack_a);
}

void	rrb(t_list **stack_b)
{
	write(1, "rrb\n", 4);
	reverse_rotate_stack(stack_b);
}

void	reverse_rotate(t_list **a, t_list **b, char *line)
{
	if (line[0] == 'r' && line[1] == 'r')
	{
		reverse_rotate_stack(a);
		reverse_rotate_stack(b);
	}
	else if (line[0] == 'r' && line[1] == 'a')
		reverse_rotate_stack(a);
	else if (line[0] == 'r' && line[1] == 'b')
		reverse_rotate_stack(b);
	else
		write(1, "Wrong Command\n", 14);
}

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*stack != NULL && ft_lstlast(*stack) != NULL)
	{
		ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
		tmp = *stack;
		tmp2 = ft_lstlast(*stack);
		while (tmp->next != tmp2)
			tmp = tmp->next;
		free(tmp2);
		tmp->next = NULL;
	}
	else
		printf("not enough numbers\n");
}