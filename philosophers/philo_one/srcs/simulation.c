/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:56:21 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/02 18:31:59 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			start_simulation(t_table *table, t_philosopher *philos)
{
	int				i;

	i = -1;
	while (++i < table->num_of_philosophers)
		pthread_create(&philos[i].tid, NULL, &simulate, &philos[i]);
	i = -1;
	while (++i < table->num_of_philosophers)
		pthread_join(philos[i].tid, NULL);
}

void			*simulate(void *philosopher)
{
	t_philosopher	*philo;
	int				must_eat_count;

	philo = (t_philosopher *)philosopher;
	must_eat_count = philo->table->number_of_times_each_philosopher_must_eat;
	while (1)
	{
		// 얘네를 모두 실행하기 전에 누군가 죽었는지를 판단하는 게 필요함.. 뮤텍스를 걸어줘야할듯..
		if (philo->table->check_anyone_dead == 1)
			break;
		if (eating(philo) == DEAD)
			break ;
		if (philo->eating_count == must_eat_count)
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

int				eating(t_philosopher *philo)
{
	int			is_time_to_die;
	int			time = get_time() - philo->table->starting_time;
	
	if (philo->time_of_recent_meal != 0)
		is_time_to_die = time - philo->time_of_recent_meal;
	if (is_time_to_die > philo->table->time_to_die)
	{
		philo->action = DEAD;
		print_message(philo, time);
		philo->table->check_anyone_dead = 1;
		return (DEAD);
	}
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	philo->time_of_recent_meal = get_time() - philo->table->starting_time;
	philo->action = EATING;
	print_message(philo, philo->time_of_recent_meal);
	usleep(philo->table->time_to_sleep * 1000);
	++philo->eating_count;
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
	return (ALIVE);
}

void			sleeping(t_philosopher *philo)
{
	int				time;

	time = get_time() - philo->table->starting_time;
	philo->action = SLEEPING;
	print_message(philo, time);
	usleep(philo->table->time_to_sleep * 1000);
}

void			thinking(t_philosopher *philo)
{
	int				time;
	
	time = get_time() - philo->table->starting_time;
	philo->action = THINKING;
	print_message(philo, time);
}

void			print_message(t_philosopher *philo, int time)
{
	pthread_mutex_lock(&philo->table->not_twisted_msg);
	if (philo->action == EATING)
	{
		printf("%d %d has taken a ", time, philo->number);
		printf("%dth and %dth fork\n", philo->left_fork + 1, philo->right_fork + 1);
		printf("%d %d is eating\n", time, philo->number);
	}
	else if (philo->action == SLEEPING)
		printf("%d %d is sleeping\n", time, philo->number);
	else if (philo->action == THINKING)
		printf("%d %d is thinking\n", time, philo->number);
	else if (philo->action == DEAD)
		printf("%d %d died\n", time, philo->number);
	pthread_mutex_unlock(&philo->table->not_twisted_msg);
}