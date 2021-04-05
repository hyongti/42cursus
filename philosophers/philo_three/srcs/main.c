/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 13:42:23 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/04/05 13:48:24 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			main(int argc, char *argv[])
{
	t_table			table;
	t_philosopher	*philosopher;

	if (is_valid_argument(argc, argv) == TRUE)
	{
		parse_argument(&table, argc, argv);
		prepare_for_simulation(&table, &philosopher);
		start_simulation(&table, philosopher);
		clean_after_simulation(&table, philosopher);
	}
	else
		return (0);
}
