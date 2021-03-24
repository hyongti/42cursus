/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_number_generator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:48:40 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/24 11:55:11 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

static int	check_double(int *arr, int cursor, int num)
{
	int	i = 0;
	
	while (i < cursor)
	{
		if (arr[i] == num)
			return (1);
		++i;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int	random_number;
	int	i = 0;
	int	count;
	int	*random_number_arr;
	
	srand(time(NULL));
	if (argc == 2)
	{
		count = atoi(argv[1]);
		random_number_arr = (int *)malloc(sizeof(int) * count);
		while (i < count)
		{
			random_number = rand() % 1000;
			if (check_double(random_number_arr, i, random_number) == 0)
			{
				random_number_arr[i] = random_number;
				printf("%d ", random_number);
				++i;
			}
		}
		free (random_number_arr);
	}
	else
		printf("The number of arguments has to be TWO\n");
}