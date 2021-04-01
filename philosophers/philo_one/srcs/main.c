/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:42:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/01 18:13:37 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		init_philosophers(t_table *table, t_philosopher **philos)
{
	int				i;
	int				num;

	i = -1;
	num = table->num_of_philosophers;
	*philos = malloc(sizeof(t_philosopher) * num);
	while (++i < num)
	{
		(*philos)[i].eating_count = 0;
		(*philos)[i].table = table;
	}
}

void		init_fork(t_table *table, t_philosopher **philo)
{
	int				i;
	int				num;

	i = -1;
	num = table->num_of_philosophers;
	table->fork = malloc(sizeof(pthread_mutex_t) * num);
	while (++i < num)
	{
		pthread_mutex_init(&table->fork[i], NULL);
		(*philo)[i].number = i;
		(*philo)[i].right_fork = i;
		if (i - 1 != 0)
			(*philo)[i].left_fork = i - 1;
		else
			(*philo)[i].left_fork = num;
	}
	table->starting_time = get_time();
}

void		set_table(t_table *table, t_philosopher **philos)
{
	init_philosophers(table, philos);
	init_fork(table, philos);
}

void			*simulate(void *philosopher)
{
	int			i;
	t_philosopher	*philo;

	i = 0;
	philo = (t_philosopher *)philosopher;
	while (philo[i].eating_count++ < philo->table->number_of_times_each_philosopher_must_eat)
		printf("philosopher %d is eating %d times\n", philo[i].number, philo[i].eating_count);
	return (0);
}

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

int			main(int argc, char *argv[])
{
	t_table			table;
	t_philosopher	*philosopher;

	if (is_valid_argument(argc, argv) == TRUE)
	{
		parse_argument(&table, argc, argv);
		set_table(&table, &philosopher);
		start_simulation(&table, philosopher);
	}
	else
		return (0);
}
