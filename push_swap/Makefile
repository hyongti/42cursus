# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 20:49:19 by hyeonkim          #+#    #+#              #
#    Updated: 2021/03/24 15:00:12 by hyeonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

CC = gcc
CFLAGS =   -fsanitize=address #-Wall -Wextra -Werror 
INCLUDE = -I./include
LIBDIR = ./libft
LIBFT = libft.a

SRCS_PUSH_SWAP_NAME = main.c version3.c #version1.c
PUSH_SWAP_DIR = ./srcs/push_swap/

SRCS_CHECKER_NAME = main.c
CHECKER_DIR = ./srcs/checker/

SRCS_COMMON_UTILS_NAME = check_valid_argument.c \
							check_sorted.c \
							init_stacks.c \
							push.c \
							swap.c \
							rotate.c \
							rotate_reverse.c \
							find_value.c \
							sort_three_in_ascending_order.c tester.c
SRCS_COMMON_UTILS_DIR = ./srcs/common_utils/

SRCS_PUSH_SWAP = $(addprefix $(PUSH_SWAP_DIR), $(SRCS_PUSH_SWAP_NAME))
SRCS_CHECKER = $(addprefix $(CHECKER_DIR), $(SRCS_CHECKER_NAME))
SRCS_COMMON_UTILS = $(addprefix $(SRCS_COMMON_UTILS_DIR), $(SRCS_COMMON_UTILS_NAME))

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)
OBJS_COMMON_UTILS = $(SRCS_COMMON_UTILS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

all : $(CHECKER) $(PUSH_SWAP)

$(CHECKER) : $(LIBDIR)/$(LIBFT) $(OBJS_CHECKER) $(OBJS_COMMON_UTILS)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(OBJS_COMMON_UTILS) $(INCLUDE) -L$(LIBDIR) -lft -o $(CHECKER)

$(PUSH_SWAP) : $(LIBDIR)/$(LIBFT) $(OBJS_PUSH_SWAP) $(OBJS_COMMON_UTILS)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(OBJS_COMMON_UTILS) $(INCLUDE) -L$(LIBDIR) -lft -o $(PUSH_SWAP)

$(LIBDIR)/$(LIBFT) :
	make -C $(LIBDIR) all

clean :
	make -C $(LIBDIR) clean
	rm -f  $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(OBJS_COMMON_UTILS)

fclean : clean
	make -C $(LIBDIR) fclean
	rm -f $(PUSH_SWAP) $(CHECKER)

re : fclean all

.PHONY : all clean re bonus