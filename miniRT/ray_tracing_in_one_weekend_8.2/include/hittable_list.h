/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:35:31 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 19:55:48 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_LIST
# define HITTABLE_LIST

#include "sphere.h"

# define SP 1

typedef struct	s_hittable_list
{
	int			type;
	void		*object;
	void		*next;
}				t_hittable_list;

t_hittable_list		*h_lstnew(int obj_type, void *object);
t_hittable_list		*h_lstlast(t_hittable_list *lst);
void				h_lstadd_back(t_hittable_list **lst, t_hittable_list *new);

#endif