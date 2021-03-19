/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:47:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/18 22:02:40 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_stacks	*stack_a;
	t_stacks	*stack_b;

	if (argc > 1)
	{
		init_stacks(stack_a, stack_b, argv);
		print_stacks(stack_a, stack_b);
	}
	else
		write(1, "Error\n", 6);
}

void	init_stacks(t_list *stack_a, t_list *stack_b, char *argv[])
{
	int	i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	while (argv[++i])
	{
		
		ft_lstadd_back(&stack_a, ft_lstnew())
	}
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	
}