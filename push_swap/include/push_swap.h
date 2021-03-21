/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:09:01 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/21 18:00:53 by hyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include "tester.h"

# define TRUE 1
# define FALSE 0

typedef int		t_bool;

t_bool	has_only_digit(char *str);
t_bool	has_valid_argument(char *argv[]);
void	init_stacks(t_list **stack_a, t_list **stack_b, char *argv[]);
void	wait_instruction_and_sort(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_1, t_list **stack_2);
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	check_stacks_sorted(t_list *stack_a, t_list *stack_b);
void	write_instruction_and_sort(t_list **stack_a, t_list **stack_b);

#endif