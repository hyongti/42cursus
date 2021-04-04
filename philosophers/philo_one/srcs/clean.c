/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:03:04 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/04 18:08:16 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	clean_after_simulation(t_table *table, t_philosopher *philo)
{
	int		i;

	i = -1;
	while (++i < table->num_of_philosophers)
		pthread_mutex_destroy(&table->fork[i]);
	pthread_mutex_destroy(&table->not_twisted_msg);
	free(table->fork);
	free(philo);
}