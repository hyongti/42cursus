/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:09:01 by hyeonkim          #+#    #+#             */
/*   Updated: 2021/03/24 17:33:52 by hyeonkim         ###   ########.fr       */
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

t_bool	has_valid_argument(int argc, char *argv[]);
t_bool	has_only_digit(char *str);
t_bool	is_in_int_range(char *str);
void	init_stacks(t_list **stack_a, t_list **stack_b, char *argv[]);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	push(t_list **stack_a, t_list **stack_b, char *line);
void	push_stack1_to_stack2(t_list **stack1, t_list **stack2);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rotate(t_list **stack_a, t_list **stack_b, char *line);
void	rotate_stack(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	reverse_rotate(t_list **stack_a, t_list **stack_b, char *line);
void	reverse_rotate_stack(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	swap(t_list **stack_a, t_list **stack_b, char *line);
void	swap_stack(t_list **stack);
int		first_of(t_list *stack);
int		second_of(t_list *stack);
int		third_of(t_list *stack);

// push_swap
void	write_instruction_to_sort_1st(t_list **stack_a, t_list **stack_b);
void	write_instruction_to_sort_2nd(t_list **stack_a, t_list **stack_b);
void	write_instruction_to_sort_3rd(t_list **stack_a, t_list **stack_b, int argc);
void	push_the_smallest_in_order(t_list **stack_a, t_list **stack_b);
void	push_a_the_smallest_in_order(t_list **stack_a, t_list **stack_b);
t_bool	check_sorted_in_ascending_order(t_list *stack);
t_bool	check_sorted_in_descending_order(t_list *stack);
void	sort_stack_b_and_push_to_a(t_list **stack_b, t_list **stack_a);
int		find_maximum_value(t_list *stack);
int		find_where_is_maximum(t_list *stack);
int		find_minimum_value(t_list *stack);
int		find_where_is_minimum(t_list *stack);
void	sort_three_in_ascending_order(t_list **stack);
void	sort_three_in_descending_order(t_list **stack);

// checker
void	wait_instruction_and_sort(t_list **stack_a, t_list **stack_b);
void	check_stacks_sorted(t_list *stack_a, t_list *stack_b);

#endif