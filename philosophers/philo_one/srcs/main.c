/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:42:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/01 20:32:09 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
	int				i = -1;

	philo = (t_philosopher *)philosopher;
	must_eat_count = philo->table->number_of_times_each_philosopher_must_eat;
	pthread_mutex_lock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_lock(&philo->table->fork[philo->right_fork]);
	while (++i < 3)
		printf("philosopher %d has taken a %dth and %dth fork\n",
			philo->number, philo->left_fork,philo->right_fork);
	pthread_mutex_unlock(&philo->table->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->table->fork[philo->right_fork]);
	return (NULL);
}
