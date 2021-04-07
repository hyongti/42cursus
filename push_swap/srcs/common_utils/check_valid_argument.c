/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:38:42 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/24 13:27:43 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	has_valid_argument(int argc, char *argv[])
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (has_only_digit(argv[i]) == FALSE)
			return (FALSE);
		if (is_in_int_range(argv[i]) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	has_only_digit(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		++i;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

t_bool	is_in_int_range(char *str)
{
	if (ft_atoll(str) > 2147483647 || ft_atoll(str) < -2147483648)
		return (FALSE);
	else
		return (TRUE);
}

