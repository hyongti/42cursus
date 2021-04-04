/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:34:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/04 17:50:48 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			print_message(t_philosopher *philo, int time)
{
	pthread_mutex_lock(&philo->table->not_twisted_msg);
	if (philo->table->check_anyone_dead == 0 &&
		philo->table->count_eat_all != philo->table->num_of_philosophers)
	{
		if (philo->action == EATING)
		{
			printf("%d %d has taken a ", time, philo->number);
			printf("%dth and %dth fork\n",
					philo->left_fork + 1, philo->right_fork + 1);
			printf("%d %d is eating %d times\n",
					time, philo->number, philo->eating_count + 1);
		}
		else if (philo->action == SLEEPING)
			printf("%d %d is sleeping\n", time, philo->number);
		else if (philo->action == THINKING)
			printf("%d %d is thinking\n", time, philo->number);
		else if (philo->action == DEAD)
			printf("%d %d died\n", time, philo->number);
	}
	pthread_mutex_unlock(&philo->table->not_twisted_msg);
}
