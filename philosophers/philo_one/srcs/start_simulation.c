/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_start_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:56:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/04 17:30:14 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			start_simulation(t_table *table, t_philosopher *philos)
{
	int				i;

	i = -1;
	while (++i < table->num_of_philosophers)
		pthread_create(&philos[i].tid, NULL, &simulation, &philos[i]);
	i = -1;
	while (++i < table->num_of_philosophers)
		pthread_join(philos[i].tid, NULL);
}
