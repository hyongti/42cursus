/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:34:00 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/02 20:39:01 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere	*sphere(t_point center, double radius)
{
	t_sphere	*sphere;

	if (!(sphere = (t_sphere *)malloc(sizeof(t_sphere))))
		return (0);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}