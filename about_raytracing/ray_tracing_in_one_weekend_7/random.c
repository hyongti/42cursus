/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:07:05 by hyeonkim          #+#    #+#             */
/*   Updated: 2020/12/03 10:12:38 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "random.h"

double		random_double(void)
{
	return ((double)rand() / ((double)RAND_MAX + 1));
}

double		random_double2(double min, double max)
{
	return (min + (max - min) * random_double());
}