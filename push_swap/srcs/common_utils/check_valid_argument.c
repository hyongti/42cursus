/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_argument.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:38:42 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 16:01:11 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	has_valid_argument(char *argv[])
{
	int		i;

	i = 0;
	while (argv[++i])
	{
		if (has_only_digit(argv[i]) == FALSE)
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
