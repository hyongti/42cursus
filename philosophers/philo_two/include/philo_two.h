/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:20:50 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 09:54:44 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>

# define TRUE 1
# define FALSE 0

# define NO_ONE_DIED 2
# define SOMEONE_DIED 3

# define TAKING_FORK 4
# define EATING 5
# define SLEEPING 6
# define THINKING 7
# define DEAD 8

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
	sem_t			*for_not_twisted_msg;
	sem_t			*fork;
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

int					ft_atoi(char *s);
int					get_time(void);
void				usleep_more_precisely(int sleeptime);

int					is_valid_argument(int argc, char *argv[]);
void				parse_argument(t_table *table, int argc, char *argv[]);
int					print_error(char *str);

void				prepare_for_simulation(t_table *table,
											t_philosopher **philos);
void				init_philosophers(t_table *table, t_philosopher **philos);
void				init_table(t_table *table, t_philosopher **philo);

void				start_simulation(t_table *table,
										t_philosopher *philosopher);
void				*simulation(void *philosopher);
void				*check_anyone_dead(void *philo);
int					eating(t_philosopher *philo);
int					sleeping(t_philosopher *philo);
int					thinking(t_philosopher *philo);
int					taking_fork(t_philosopher *philo);
void				print_message(t_philosopher *philo, int time);

void				clean_after_simulation(t_table *table,
												t_philosopher *philo);

#endif
