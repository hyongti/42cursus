/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 20:14:06 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/01 21:06:07 by hyeonkim         ###   ########.fr       */
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
		(*philo)[i].number = i + 1;
		(*philo)[i].right_fork = i;
		if (i - 1 >= 0)
			(*philo)[i].left_fork = i - 1;
		else
			(*philo)[i].left_fork = num - 1;
	}
	table->starting_time = get_time();
}

void		set_table(t_table *table, t_philosopher **philos)
{
	init_philosophers(table, philos);
	init_fork(table, philos);
}