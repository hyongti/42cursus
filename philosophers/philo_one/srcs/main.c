#include "philo_one.h"

int			main(int argc, char *argv[])
{
	t_condition	condition;

	if (is_valid_argument(argc, argv) == TRUE)
	{
		init_condition(&condition, argc, argv);
		start_simulation(&condition);
	}
	else
		return (0);
}

void		*eat(void *num)
{

}

void		make_fork(pthread_mutex_t *fork[], t_condition *condition)
{
	int		i;

	i = 0;
	while (i++ < condition->num_of_philosophers)
		pthread_mutex_init(&fork[i], NULL);
}

void		start_simulation(t_condition *condition)
{
	int				i;
	int				philo_num[condition->num_of_philosophers];
	pthread_t		philosopher[condition->num_of_philosophers];
	pthread_mutex_t	fork[condition->num_of_philosophers];

	// while (i++ < condition->num_of_philosophers)
	// 	pthread_mutex_init(&fork[i], NULL);
	make_fork(&fork, condition);
	while (i++ < condition->num_of_philosophers)
		pthread_create(&philosopher[i], NULL, eat, &philo_num[i]);
	for (i = 0; i < condition->num_of_philosophers; i++)
		pthread_join(philosopher[i], NULL);
}

