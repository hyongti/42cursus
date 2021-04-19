/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 16:37:44 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/04 17:51:32 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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

int			print_error(char *str)
{
	printf("Wrong arg[%s\n", str);
	return (FALSE);
}
