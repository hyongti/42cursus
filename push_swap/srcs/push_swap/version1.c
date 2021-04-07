/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   version1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:07:34 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/24 13:29:26 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_instruction_to_sort_1st(t_list **stack_a, t_list **stack_b)
{
	int		max_value;
	int		min_value;
	int		count = 0;
	
	if (check_sorted_in_ascending_order(*stack_a) == TRUE)
		return ;
	if (ft_lstsize(*stack_a) > 3)
		push_the_smallest_in_order(stack_a, stack_b);
	sort_three_in_ascending_order(stack_a);
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_b, stack_a);
	print_stacks(*stack_a, *stack_b);
}

void	push_the_smallest_in_order(t_list **stack_a, t_list **stack_b)
{
	int		min_value;
	int		where;

	min_value = find_minimum_value(*stack_a);
	while (ft_lstsize(*stack_a) != 3)
	{
		if (min_value == *(int *)((*stack_a)->content))
		{
			pb(stack_a, stack_b);
			if (ft_lstsize(*stack_a) != 0)
				min_value = find_minimum_value(*stack_a);
		}
		else if ((where = find_where_is_minimum(*stack_a)) > (ft_lstsize(*stack_a) / 2))
			rra(stack_a);
		else
		{
			if (*(int *)((*stack_a)->content) < *(int *)((*stack_a)->next->content))
				ra(stack_a);
			else
				sa(stack_a);
		}
		print_stacks(*stack_a, *stack_b);
	}
}
