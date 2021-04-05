/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:00:14 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 18:02:24 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			manage_processes(t_table *table, t_philosopher *philos)
{
	int				i;
	pthread_t		eat_all;
	pthread_t		someone_died;

	i = -1;
	sem_unlink("/stop");
	philos->to_stop_simulation = sem_open("/stop", O_CREAT | O_EXCL, 0777, 0);
	pthread_create(&someone_died, NULL, &stop_when_died, (void *)philos);
	pthread_create(&eat_all, NULL, &stop_everyone_eat_all, (void *)philos);
	sem_wait(philos->to_stop_simulation);
	while (++i < table->num_of_philosophers)
		kill(philos[i].pid, SIGKILL);
}

void			*stop_everyone_eat_all(void *philosopher)
{
	t_philosopher	*philo;
	int				eat_all;

	philo = (t_philosopher *)philosopher;
	eat_all = 0;
	while (1)
	{
		sem_wait(philo->table->check_eat_all);
		eat_all++;
		if (eat_all == philo->table->num_of_philosophers)
		{
			sem_post(philo->to_stop_simulation);
			break ;
		}
	}
	return (NULL);
}

void			*stop_when_died(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	sem_wait(philo->table->check_dead);
	sem_post(philo->to_stop_simulation);
	return (NULL);
}
