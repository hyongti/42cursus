/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:45:06 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/23 20:25:55 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_of(t_list *stack)
{
	return (*(int *)(stack->content));
}

static int	second_of(t_list *stack)
{
	return (*(int *)(stack->next->content));
}

static int	third_of(t_list *stack)
{
	return (*(int *)(ft_lstlast(stack)->content));
}

void	write_instruction_to_sort_2nd(t_list **stack_a, t_list **stack_b)
{
	while (check_sorted_in_ascending_order(*stack_a) == FALSE)
	{
		while (ft_lstsize(*stack_b) < 3)
		{
			pb(stack_a, stack_b);
			print_stacks(*stack_a, *stack_b);
		}
		sort_three_in_descending_order(stack_b);
		while (ft_lstsize(*stack_b) > 0)
		{
			while (first_of(*stack_a) < first_of(*stack_b))
			{
				printf("min : %d\n", find_minimum_value(*stack_a));
				printf("first : %d\n", first_of(*stack_a));
				if (first_of(*stack_a) == find_minimum_value(*stack_a))
				{
					pa(stack_b, stack_a);
					print_stacks(*stack_a, *stack_b);
				}
				else
				{
					ra(stack_a);
					print_stacks(*stack_a, *stack_b);
					ra(stack_a);
					print_stacks(*stack_a, *stack_b);
				}
			}
			pa(stack_b, stack_a);
			print_stacks(*stack_a, *stack_b);
			ra(stack_a);
			print_stacks(*stack_a, *stack_b);
		}	
	}
}

void	sort_three_in_descending_order(t_list **stack)
{
	if (check_sorted_in_descending_order(*stack) == TRUE)
		return ;
	else if (first_of(*stack) == find_minimum_value(*stack))
	{
		rb(stack);
		if (first_of(*stack) < second_of(*stack))
			sb(stack);
	}
	else if (first_of(*stack) == find_maximum_value(*stack))
	{
		rrb(stack);
		sb(stack);
	}
	else
	{
		if (third_of(*stack) == find_maximum_value(*stack))
			rrb(stack);
		else
			sb(stack);
	}
}