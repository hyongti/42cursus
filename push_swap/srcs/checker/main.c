/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:47:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/22 21:24:43 by hyeonkim         ###   ########.fr       */
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
	int		count = 0;
	
	while ((gnl_return = get_next_line(0, &line)) > 0)
	{
		if (line[0] == 'p')
			push(stack_a, stack_b, line + 1);
		else if (line[0] == 's')
			swap(stack_a, stack_b, line + 1);
		else if (line[0] == 'r' && ft_strlen(line) == 2)
			rotate(stack_a, stack_b, line + 1);
		else if (line[0] == 'r' && ft_strlen(line) == 3)
			reverse_rotate(stack_a, stack_b, line + 1);
		else
			write(2, "WRONG COMMAND\n", 14);
		free(line);
		line = NULL;
		write(1, "\n", 1);
		print_stacks(*stack_a, *stack_b);
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
