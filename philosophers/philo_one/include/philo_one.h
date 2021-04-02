/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:20:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/02 18:13:39 by hyeonkim         ###   ########.fr       */
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

# define ALIVE 2
# define DEAD 3

# define EATING 4
# define SLEEPING 5
# define THINKING 6

typedef struct		s_table
{
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				count_eat_all;
	int				starting_time;
	int				check_anyone_dead;
	pthread_mutex_t	not_twisted_msg;
	pthread_mutex_t	*fork;
}					t_table;

typedef struct		s_philosopher
{
	int				number;
	int				left_fork;
	int				right_fork;
	int				eating_count;
	int				time_of_recent_meal;
	int				action;
	t_table			*table;
	pthread_t		tid;
}					t_philosopher;


int				ft_atoi(char *s);
int				get_time(void);

int				is_valid_argument(int argc, char *argv[]);
void			parse_argument(t_table *table ,int argc, char *argv[]);

void			prepare_for_simulation(t_table *table, t_philosopher **philos);
void			init_philosophers(t_table *table, t_philosopher **philos);
void			init_table(t_table *table, t_philosopher **philo);

void			start_simulation(t_table *table, t_philosopher *philosopher);
void			*simulate(void *philosopher);
int				eating(t_philosopher *philo);
void			sleeping(t_philosopher *philo);
void			thinking(t_philosopher *philo);
void			print_message(t_philosopher *philo, int time);

#endif