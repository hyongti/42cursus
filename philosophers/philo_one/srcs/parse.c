#include "philo_one.h"

int			is_valid_argument(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("The number of argument should be 5 or 6\n");
		return (0);
	}
	// check arg is integer
	return (1);
}

void	init_condition(t_condition *condition ,int argc, char *argv[])
{
	condition->num_of_philosohpers = ft_atoi((const char *)argv[1]);
	condition->time_to_die = ft_atoi((const char *)argv[2]);
	condition->time_to_eat = ft_atoi((const char *)argv[3]);
	condition->time_to_sleep = ft_atoi((const char *)argv[4]);
	if (argc == 6)
		condition->number_of_times_each_philosopher_must_eat
			= ft_atoi((const char *)argv[5]);
	else
		condition->number_of_times_each_philosopher_must_eat = -1;
}