# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 18:59:15 by hyeonkim          #+#    #+#              #
#    Updated: 2021/01/04 15:55:16 by hyeonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minirt
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I./
MAKE	=	make
LIBFT	=	/libft/libft.a
SRCDIR	=	./src

all : $(NAME)

$(NAME) : 
	gcc -Wall -Wextra -Werror -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit *.c ./libft/*.c ./src/*.c ./src/*/*.c -I ./include -I ./mlx -D BUFFER_SIZE=1 -o $(NAME)

run : $(NAME)
	./$(NAME) scene.rt > image.ppm
	open image.ppm

re :
	rm minirt
	gcc -Wall -Wextra -Werror -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit *.c ./libft/*.c ./src/*.c ./src/*/*.c -I ./include -I ./mlx -D BUFFER_SIZE=1 -o $(NAME)