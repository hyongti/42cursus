/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:09:01 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/22 21:33:16 by hyeonkim         ###   ########.fr       */
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

t_bool	has_valid_argument(char *argv[]);
t_bool	has_only_digit(char *str);
t_bool	is_in_int_range(char *str);
void	init_stacks(t_list **stack_a, t_list **stack_b, char *argv[]);

// push_swap
void	write_instruction_to_sort(t_list **stack_a, t_list **stack_b);
t_bool	check_sorted_in_ascending_order(t_list *stack);
t_bool	check_sorted_in_descending_order(t_list *stack);
void	sort_stack_b_and_push_to_a(t_list **stack_b, t_list **stack_a);
int		find_maximum_value(t_list *stack);
int		find_minimum_value(t_list *stack);

// checker
void	wait_instruction_and_sort(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b, char *line);
void	push_stack1_to_stack2(t_list **stack1, t_list **stack2);
void	rotate(t_list **stack_a, t_list **stack_b, char *line);
void	rotate_stack(t_list **stack);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, char *line);
void	reverse_rotate_stack(t_list **stack);
void	swap(t_list **stack_a, t_list **stack_b, char *line);
void	swap_stack(t_list **stack);
void	check_stacks_sorted(t_list *stack_a, t_list *stack_b);

#endif