/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:36:07 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/06 18:45:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hittable.h"

t_hittable_list		*h_lstnew(int obj_type, void *object)
{
	t_hittable_list	*new;

	if (!(new = (t_hittable_list *)malloc(sizeof(new))))
		return (0);
	new->next = 0;
	new->type = obj_type;
	new->object = object;
	return (new);
}

t_hittable_list		*h_lstlast(t_hittable_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void				h_lstadd_back(t_hittable_list **lst, t_hittable_list *new)
{
	t_hittable_list	*tmp;

	if (!lst || !new)
		return ;
	tmp = h_lstlast(*lst);
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp->next = new;
}
