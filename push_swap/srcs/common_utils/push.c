/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:23:38 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 17:24:23 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	tmp = *stack1;
	if (*stack1 == NULL)
		printf("stack is empty\n");
	else
	{
		*stack1 = (*stack1)->next;
		ft_lstadd_front(stack2, tmp);
	}
}
