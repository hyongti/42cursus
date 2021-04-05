/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_for_simulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:14:06 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 09:48:10 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void		prepare_for_simulation(t_table *table, t_philosopher **philos)
{
	init_philosophers(table, philos);
	init_table(table, philos);
}

void		init_philosophers(t_table *table, t_philosopher **philos)
{
	int				i;
	int				num;

	i = -1;
	num = table->num_of_philosophers;
	*philos = malloc(sizeof(t_philosopher) * num);
	while (++i < num)
	{
		(*philos)[i].number = i + 1;
		(*philos)[i].eating_count = 0;
		(*philos)[i].time_of_recent_meal = 0;
		(*philos)[i].table = table;
		(*philos)[i].action = 0;
	}
}

void		init_table(t_table *table, t_philosopher **philo)
{
	int				i;
	int				num;

	i = -1;
	num = table->num_of_philosophers;
	sem_unlink("/file");
	sem_unlink("/clean_msg");
	table->fork = sem_open("/file",O_CREAT | O_EXCL, 
						0777, table->num_of_philosophers);
	table->for_not_twisted_msg = sem_open("/clean_msg", O_CREAT | O_EXCL,
						0777, 1);
	table->starting_time = get_time();
	table->count_eat_all = 0;
	table->check_anyone_dead = 0;
}
