/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:44:08 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/23 21:45:54 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_maximum_value(t_list *stack)
{
	t_list	*finder;
	int		max;

	finder = stack;
	max = *(int *)(stack->content);
	while (finder != NULL && finder->next != NULL)
	{
		if (max < *(int *)(finder->next->content))
			max = *(int *)(finder->next->content);
		finder = finder->next;
	}
	return (max);
}

int		find_where_is_maximum(t_list *stack)
{
	int		max;
	int		where;
	t_list	*finder;

	max = find_maximum_value(stack);
	where = 0;
	finder = stack;
	while (finder != NULL && finder->next != NULL)
	{
		++where;
		if (max == *(int *)(finder->content))
			break ;
		finder = finder->next;
	}
	return (where);
}

int		find_minimum_value(t_list *stack)
{
	t_list	*finder;
	int		min;

	finder = stack;
	min = *(int *)(stack->content);
	while (finder != NULL && finder->next != NULL)
	{
		if (min > *(int *)(finder->next->content))
			min = *(int *)(finder->next->content);
		finder = finder->next;
	}
	return (min);
}

int		find_where_is_minimum(t_list *stack)
{
	int		min;
	int		where;
	t_list	*finder;

	min = find_minimum_value(stack);
	where = 0;
	finder = stack;
	while (finder != NULL && finder->next != NULL)
	{
		++where;
		if (min == *(int *)(finder->content))
			break ;
		finder = finder->next;
	}
	return (where);
}