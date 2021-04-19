/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:56:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 18:01:16 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			start_simulation(t_table *table, t_philosopher *philos)
{
	int				i;

	i = -1;
	while (++i < table->num_of_philosophers)
	{
		philos[i].pid = fork();
		if (philos[i].pid == 0)
			break ;
	}
	if (i != table->num_of_philosophers)
		simulation(&philos[i]);
	else
		manage_processes(table, philos);
}

void			*simulation(void *philosopher)
{
	t_philosopher	*philo;
	int				must_eat_count;
	pthread_t		is_someone_dead;

	philo = (t_philosopher *)philosopher;
	must_eat_count = philo->table->number_of_times_each_philosopher_must_eat;
	if (philo->number % 2 == 0)
		usleep(philo->table->time_to_sleep * 1000);
	pthread_create(&is_someone_dead, NULL, &check_anyone_dead, philo);
	while (1)
	{
		if (taking_fork(philo) == SOMEONE_DIED)
			break ;
		if (eating(philo) == SOMEONE_DIED)
			break ;
		if (philo->eating_count == must_eat_count)
			break ;
		if (sleeping(philo) == SOMEONE_DIED)
			break ;
		if (thinking(philo) == SOMEONE_DIED)
			break ;
	}
	pthread_join(is_someone_dead, NULL);
	sem_post(philo->table->check_eat_all);
	return (NULL);
}
