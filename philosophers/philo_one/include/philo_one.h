/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:20:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/31 19:29:05 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct	s_contidion
{
	int			num_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
}				t_condition;

typedef struct	s_philosopher
{
	int			state;
	
}				t_philosopher;


int				ft_atoi(const char *s);

int				is_valid_argument(int argc, char *argv[]);
void			init_condition(t_condition *condition ,int argc, char *argv[]);
void			start_simulation(t_condition *condition);

#endif