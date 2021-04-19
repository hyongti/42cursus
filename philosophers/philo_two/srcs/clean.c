/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 18:03:04 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 13:30:30 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	clean_after_simulation(t_table *table, t_philosopher *philo)
{
	sem_close(table->fork);
	sem_close(table->for_not_twisted_msg);
	free(philo);
}
