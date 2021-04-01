/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:29:22 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/01 11:17:51 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static int		ft_isspace(char c)
{
		if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
						|| c == ' ')
				return (1);
		return (0);
}

static int		check_over_range(int count, int sign, int result)
{
	if (count > 20 && sign == 1)
		return (-1);
	else if (count > 20 && sign == -1)
		return (0);
	else
		return (result);
}

int				ft_atoi(char *s)
{
		int			idx;
		int			sign;
		int			cnt;
		long long	result;

		cnt = 0;
		idx = 0;
		sign = 1;
		result = 0;
		while (s[idx] && (ft_isspace(s[idx]) == 1))
				idx++;
		if (s[idx] == '-')
			sign *= -1;
		if (s[idx] == '-' || s[idx] == '+')
			idx++;
		while (s[idx] && s[idx] >= '0' && s[idx] <= '9')
		{
				result = result * 10 + (s[idx] - '0') * sign;
				idx++;
				cnt++;
		}
		return (check_over_range(cnt, sign, result));
}