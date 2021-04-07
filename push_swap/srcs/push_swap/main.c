/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:08:11 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/24 17:33:58 by hyeonkim         ###   ########.fr       */
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
			// write_instruction_to_sort_1st(&stack_a, &stack_b);
			// write_instruction_to_sort_2nd(&stack_a, &stack_b);
			write_instruction_to_sort_3rd(&stack_a, &stack_b, argc);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
}
