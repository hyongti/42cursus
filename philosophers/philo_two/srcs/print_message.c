/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:34:47 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 09:57:48 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void			print_message(t_philosopher *philo, int time)
{
	sem_wait(philo->table->for_not_twisted_msg);
	if (philo->table->check_anyone_dead == 0)
	{
		if (philo->action == TAKING_FORK)
			printf("%d %d has taken a fork\n", time, philo->number);
		else if (philo->action == EATING)
		{
			printf("%d %d has taken a fork\n", time, philo->number);
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
	sem_post(philo->table->for_not_twisted_msg);
}
