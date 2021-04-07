/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:09:12 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/23 19:09:21 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
