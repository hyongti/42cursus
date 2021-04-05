/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:56:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 17:15:20 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			*stop_everyone_eat_all(void *philosopher)
{
	t_philosopher	*philo;
	int			eat_all;

	philo = (t_philosopher *)philosopher;
	eat_all = 0;
	while (1)
	{
		sem_wait(philo->table->check_eat_all);
		eat_all++;
		if (eat_all == philo->table->num_of_philosophers)
		{
			sem_post(philo->to_stop_simulation);
			break;
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

void			wait_child_process(t_table *table, t_philosopher *philos)
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
		wait_child_process(table, philos);
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
