# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkim <hyeonkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/18 20:49:19 by hyeonkim          #+#    #+#              #
#    Updated: 2021/03/18 21:29:44 by hyeonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap

CC = gcc
CFLAGS = -fsanitize=address #-Wall -Wextra -Werror 
INCLUDE = -I./include
LIBDIR = ./libft
LIBFT = libft.a

SRCS_PUSH_SWAP_NAME = main.c
PUSH_SWAP_DIR = ./srcs/push_swap/

SRCS_CHECKER_NAME = main.c
CHECKER_DIR = ./srcs/checker/

SRCS_PUSH_SWAP = $(addprefix $(PUSH_SWAP_DIR), $(SRCS_PUSH_SWAP_NAME))
SRCS_CHECKER = $(addprefix $(CHECKER_DIR), $(SRCS_CHECKER_NAME))

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

all : $(CHECKER) $(PUSH_SWAP)

$(CHECKER) : $(LIBDIR)/$(LIBFT) $(OBJS_CHECKER)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(INCLUDE) -L$(LIBDIR) -lft -o $(CHECKER)

$(PUSH_SWAP) : $(LIBDIR)/$(LIBFT) $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(INCLUDE) -L$(LIBDIR) -lft -o $(PUSH_SWAP)

$(LIBDIR)/$(LIBFT) :
	make -C $(LIBDIR) all

clean :
	make -C $(LIBDIR) clean
	rm -f $(OBJS)

fclean :
	make -C $(LIBDIR) fclean
	rm -f $(PUSH_SWAP) $(CHECKER)

re : fclean all

.PHONY : all clean re ppm open run