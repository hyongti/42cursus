/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:55:37 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 17:56:01 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_list **stack_a, t_list **stack_b, char *argv[])
{
	int		i;
	int		*argv_int;

	i = 0;
	*stack_a = NULL;
	*stack_b = NULL;
	while (argv[++i])
	{
		argv_int = (int *)malloc(sizeof(int));
		*argv_int = ft_atoi(argv[i]);
		ft_lstadd_back(stack_a, ft_lstnew(argv_int));
	}
}
