#include "philo_one.h"

int			print_error(char *str)
{
	printf("Wrong arg[%s\n", str);
	return (FALSE);
}

int			is_valid_argument(int argc, char *argv[])
{
	int		ret;

	ret = TRUE;
	if (argc != 5 && argc != 6)
		ret = print_error("number of arguments");	
	else
	{
		if (ft_atoi(argv[1]) <= 0)
			ret = print_error("1]: number of philosophers");
		if (ft_atoi(argv[2]) <= 0)
			ret = print_error("2]: time to die");
		if (ft_atoi(argv[3]) <= 0)
			ret = print_error("3]: time to eat");
		if (ft_atoi(argv[4]) <= 0)
			ret = print_error("4]: time to sleep");
		if (argc == 6 && ft_atoi(argv[5]) <= 0)
			ret = print_error("5]: number of times each philosopher must eat");
	}
	return (ret);
}

void	parse_argument(t_table *table ,int argc, char *argv[])
{
	table->num_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->number_of_times_each_philosopher_must_eat
			= ft_atoi(argv[5]);
	else
		table->number_of_times_each_philosopher_must_eat = -1;
}