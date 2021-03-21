/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:08:11 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 18:25:10 by hyeonkim         ###   ########.fr       */
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
			test_init_stacks(stack_a, stack_b);
			write_instruction_and_sort(&stack_a, &stack_b);
		}
		else
			write(2, "Error\n", 6);
	}
	else
		write(2, "Error\n", 6);
}

void	write_instruction_and_sort(t_list **stack_a, t_list **stack_b)
{
	// 명령어 리스트를 표준출력으로 출력
	// checker에서 파이프를 통해 표준입력으로 받는다.
}