/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_face_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:58:48 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/11/30 20:00:57 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

void	set_face_normal(t_vec *ray, t_record *rec)
{
    if (v_dot(*ray, rec->normal) > 0.0)
        v_multiply(rec->normal, -1.0);
    else
        return;
}