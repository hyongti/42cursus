/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:47:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 18:13:55 by hyeonkim         ###   ########.fr       */
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
			// test_init_stacks(stack_a, stack_b);
			wait_instruction_and_sort(&stack_a, &stack_b);
			check_stacks_sorted(stack_a, stack_b);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
}

void	wait_instruction_and_sort(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		gnl_return;

	while ((gnl_return = get_next_line(0, &line)) > 0)
	{
		if (ft_strncmp(line, "pb", 2) == 0)
			push(stack_a, stack_b);
		else if (ft_strncmp(line, "pa", 2) == 0)
			push(stack_b, stack_a);
		else if (ft_strncmp(line, "sa", 2) == 0)
			swap(stack_a);
		else if (ft_strncmp(line, "sb", 2) == 0)
			swap(stack_b);
		else if (ft_strncmp(line, "ra", 2) == 0)
			rotate(stack_a);
		else if (ft_strncmp(line, "rb", 2) == 0)
			rotate(stack_b);
		free(line);
		// test_init_stacks(*stack_a, *stack_b);
	}
}

void	check_stacks_sorted(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if (*(int *)(stack_a->content)
			< (*(int *)(stack_a->next->content)))
			stack_a = stack_a->next;
		else
		{
			write(1, "KO\n", 3);
			return ;
		}
	}
	write(1, "OK\n", 3);
	return ;
}