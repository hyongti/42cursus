/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_in_ascending_order.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:01:07 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/24 13:34:54 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_of(t_list *stack)
{
	return (*(int *)(stack->content));
}

int	second_of(t_list *stack)
{
	return (*(int *)(stack->next->content));
}

int	third_of(t_list *stack)
{
	return (*(int *)(ft_lstlast(stack)->content));
}

void	sort_three_in_ascending_order(t_list **stack)
{
	if (check_sorted_in_ascending_order(*stack) == TRUE)
		return ;
	else if (first_of(*stack) == find_maximum_value(*stack))
	{
		ra(stack);
		if (first_of(*stack) > second_of(*stack))
			sa(stack);
	}
	else if (first_of(*stack) == find_minimum_value(*stack))
	{
		rra(stack);
		sa(stack);
	}
	else
	{
		if (third_of(*stack) == find_minimum_value(*stack))
			rra(stack);
		else
			sa(stack);
	}
}