/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:23:38 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 18:11:12 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack != NULL && ft_lstlast(*stack) != NULL)
	{
		// tmp = (*stack)->content;
		// (*stack)->content = ft_lstlast(*stack)->content;
		// ft_lstlast(*stack)->content = tmp;
		tmp = *stack;
		*stack = (*stack)->next;
		ft_lstadd_back(stack, tmp);
		tmp->next = NULL;
	}
	else
		printf("not enough numbers\n");
}
