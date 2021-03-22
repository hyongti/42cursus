/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:08:11 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/22 22:21:33 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		if (has_valid_argument(argv) == TRUE)
		{
			init_stacks(&stack_a, &stack_b, argv);
			write_instruction_to_sort(&stack_a, &stack_b);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
}

void	write_instruction_to_sort(t_list **stack_a, t_list **stack_b)
{
	int		max_value;
	int		count = 0;
	// printf("min : %d\n", min_value);
	while (ft_lstsize(*stack_a) != 0)
	{
		push_stack1_to_stack2(stack_a, stack_b);
		print_stacks(*stack_a, *stack_b);
		write(1, "pb\n", 3);
		printf("count : %d\n\n", ++count);
		sleep (1);
	}
	max_value = find_maximum_value(*stack_b);
	while (ft_lstsize(*stack_b) != 0)
	{
		if (max_value == *(int *)((*stack_b)->content))
		{
			push_stack1_to_stack2(stack_b, stack_a);
			write(1, "pb\n", 3);
			if (ft_lstsize(*stack_b) != 0)
				max_value = find_maximum_value(*stack_b);
				
		}
		else if (*(int *)(ft_lstlast(*stack_b)->content) == max_value)
		{
			reverse_rotate_stack(stack_b);
			write(1, "rrb\n", 4);
		}
		else
		{
			if (*(int *)((*stack_b)->content) > *(int *)((*stack_b)->next->content))
			{
				rotate_stack(stack_b);
				write(1, "ra\n", 3);
			}
			else
			{
				swap_stack(stack_b);
				write(1, "sa\n", 3);
			}
		}
		sleep (1);
		print_stacks(*stack_a, *stack_b);
		printf("count : %d\n\n", ++count);
	}
}

int		find_maximum_value(t_list *stack)
{
	t_list	*finder;
	int		max;

	finder = stack;
	max = *(int *)(stack->content);
	while (finder != NULL && finder->next != NULL)
	{
		if (max < *(int *)(finder->next->content))
			max = *(int *)(finder->next->content);
		finder = finder->next;
	}
	return (max);
}

int		find_minimum_value(t_list *stack)
{
	t_list	*finder;
	int		min;

	finder = stack;
	min = *(int *)(stack->content);
	while (finder != NULL && finder->next != NULL)
	{
		if (min > *(int *)(finder->next->content))
			min = *(int *)(finder->next->content);
		finder = finder->next;
	}
	return (min);
}

// void	sort_stack_b_and_push_to_a(t_list **stack_b, t_list **stack_a)
// {
// 	int		first;
// 	int		second;
// 	int		third;
	
// 	first = *(int *)((*stack_b)->content);
// 	second = *(int *)((*stack_b)->next)->content;
// 	third = *(int *)(ft_lstlast(*stack_b)->content);
// 	if (first < second && first < third)
// 	{
// 		if (second > third)
// 			rotate_stack(stack_b);
// 		else
// 		{
// 			rotate_stack(stack_b);
// 			swap_stack(stack_b);
// 		}
// 	}
// 	else if (second < first && second < third)
// 	{
// 		if (first > third)
// 		{
// 			swap_stack(stack_b);
// 			rotate_stack(stack_b);
// 		}
// 		else
// 			reverse_rotate_stack(stack_b);
// 	}
// 	else if (third < first && third < second)
// 	{
// 		if (second > first)
// 			swap_stack(stack_b);
// 	}
// 	// while (ft_lstsize(*stack_b) != 0)
// 	// 	push_stack1_to_stack2(stack_b, stack_a);
// }

t_bool	check_sorted_in_ascending_order(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (*(int *)(stack->content)
			< (*(int *)(stack->next->content)))
			stack = stack->next;
		else
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_sorted_in_descending_order(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (*(int *)(stack->content)
			> (*(int *)(stack->next->content)))
			stack = stack->next;
		else
			return (FALSE);
	}
	return (TRUE);
}