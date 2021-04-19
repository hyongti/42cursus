/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:39:11 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 11:33:30 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			*check_anyone_dead(void *philosopher)
{
	t_philosopher	*philo;
	int				must_eat_count;
	int				time;

	philo = (t_philosopher *)philosopher;
	must_eat_count = philo->table->number_of_times_each_philosopher_must_eat;
	while (1)
	{
		time = get_time() - philo->table->starting_time;
		if (must_eat_count != -1 && philo->eating_count >= must_eat_count)
			break ;
		if (time - philo->time_of_recent_meal > philo->table->time_to_die)
		{
			philo->action = DEAD;
			print_message(philo, time);
			philo->table->check_anyone_dead = 1;
			break ;
		}
	}
	return (NULL);
}

int				taking_fork(t_philosopher *philo)
{
	int				time;

	if (philo->table->check_anyone_dead == 1)
		return (SOMEONE_DIED);
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	time = get_time() - philo->table->starting_time;
	philo->action = TAKING_FORK;
	print_message(philo, time);
	return (NO_ONE_DIED);
}

int				eating(t_philosopher *philo)
{
	int				must_eat_count;

	must_eat_count = philo->table->number_of_times_each_philosopher_must_eat;
	if (philo->table->check_anyone_dead == TRUE)
		return (SOMEONE_DIED);
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	philo->time_of_recent_meal = get_time() - philo->table->starting_time;
	philo->action = EATING;
	print_message(philo, philo->time_of_recent_meal);
	usleep(philo->table->time_to_eat * 1000);
	++philo->eating_count;
	if (philo->eating_count >= must_eat_count)
		++philo->table->count_eat_all;
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
	return (NO_ONE_DIED);
}

int				sleeping(t_philosopher *philo)
{
	int				time;

	if (philo->table->check_anyone_dead == TRUE)
		return (SOMEONE_DIED);
	time = get_time() - philo->table->starting_time;
	philo->action = SLEEPING;
	print_message(philo, time);
	usleep(philo->table->time_to_sleep * 1000);
	return (NO_ONE_DIED);
}

int				thinking(t_philosopher *philo)
{
	int				time;

	if (philo->table->check_anyone_dead == TRUE)
		return (SOMEONE_DIED);
	time = get_time() - philo->table->starting_time;
	philo->action = THINKING;
	print_message(philo, time);
	return (NO_ONE_DIED);
}
