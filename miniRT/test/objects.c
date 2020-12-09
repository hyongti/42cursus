/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:36:07 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/08 11:07:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_objects		*objects_new(int obj_type, void *object)
{
	t_objects	*new;

	if (!(new = (t_objects *)malloc(sizeof(new))))
		return (0);
	new->next = 0;
	new->type = obj_type;
	new->object = object;
	return (new);
}

t_objects		*objects_last(t_objects *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void				objects_add_back(t_objects **lst, t_objects *new)
{
	t_objects	*tmp;

	if (!lst || !new)
		return ;
	tmp = objects_last(*lst);
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	tmp->next = new;
}
