/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:35:31 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/10 20:42:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

#include "make_object.h"

# define LIGHT 0
# define SP 1
# define PL 2
# define TR 3
# define CY 4

typedef struct	s_objects
{
	int			type;
	void		*object;
	void		*next;
}				t_objects;

t_objects		*objects_new(int obj_type, void *object);
t_objects		*objects_last(t_objects *lst);
void			objects_add_back(t_objects **lst, t_objects *new);

#endif