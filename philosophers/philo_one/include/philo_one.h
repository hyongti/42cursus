/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:20:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/01 18:11:29 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

# define TRUE 1
# define FALSE 0

typedef struct		s_table
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	unsigned int	starting_time;
	pthread_mutex_t	*fork;
}					t_table;

typedef struct		s_philosopher
{
	int				number;
	int				left_fork;
	int				right_fork;
	int				eating_count;
	t_table			*table;
	pthread_t		tid;
}					t_philosopher;


int				ft_atoi(char *s);
unsigned int	get_time(void);

int				is_valid_argument(int argc, char *argv[]);
void			parse_argument(t_table *table ,int argc, char *argv[]);
void			start_simulation(t_table *table, t_philosopher *philosopher);

#endif