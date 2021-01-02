/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:35:31 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/01/02 01:12:48 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

#include "make_object.h"
#include "common_utils.h"

# define LIGHT 0
# define SP 1
# define PL 2
# define TR 3
# define CY 4
# define SQ 5
# define CO 6
# define CAM 20

typedef struct	s_objects
{
	int			type;
	void		*object;
	void		*next;
}				t_objects;

t_objects		*obj_new(int obj_type, void *object);
t_objects		*obj_last(t_objects *lst);
void			obj_add_back(t_objects **lst, t_objects *new);

#endif