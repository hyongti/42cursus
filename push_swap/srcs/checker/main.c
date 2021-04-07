/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:47:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/24 13:11:00 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc > 1)
	{
		if (has_valid_argument(argc, argv) == TRUE)
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
		// print_stacks(*stack_a, *stack_b);
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

// 298 132 146 388 309 368 418 31 421 404 159 479 381 240 188 166 128 257 136 145 27 266 361 11 66 195 375 466 428 455 319 392 120 118 129 399 67 69 201 37 112 426 484 114 412 367 306 217 462 447 147 303 197 246 208 25 75 385 84 179 491 359 101 106 362 398 290 360 148 64 333 68 121 133 204 427 203 191 13 449 70 156 336 317 90 230 89 332 149 415 36 226 347 24 14 110 496 123 339 138