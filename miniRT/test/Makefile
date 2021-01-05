# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonkim <hyeonkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 18:59:15 by hyeonkim          #+#    #+#              #
#    Updated: 2021/01/05 16:21:35 by hyeonkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minirt
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I./
MAKE	=	make
LIBFT	=	/libft/libft.a
SRCDIR	=	./src
MLX		=	libmlx.dylib
MLX_DIR	=	./mlx

all : $(NAME)

$(NAME) : 
	gcc -Wall -Wextra -Werror -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit *.c ./libft/*.c ./src/*.c ./src/*/*.c -I ./include -I ./mlx -D BUFFER_SIZE=1 -o $(NAME)
	install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

run : $(NAME)
	./$(NAME) scene.rt > image.ppm
	open image.ppm

re :
	rm minirt
	gcc -Wall -Wextra -Werror -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit *.c ./libft/*.c ./src/*.c ./src/*/*.c -I ./include -I ./mlx -D BUFFER_SIZE=1 -o $(NAME)
	install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)

# NAME = minirt
# CC = gcc
# RM = rm -rf
# CFLAG =  -O2 -g3 -fsanitize=address # -Wall -Wextra -Werror
# MAKE = make
# MLX = libmlx.dylib
# MLX_DIR = ./mlx
# LIBFT = libft.a
# LIBFT_DIR = ./libft
# LIB_FLAG = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -L $(LIBFT_DIR) -lft
# INCLUDE = -I./include -I./libft -I./mlx

# all : $(NAME)

# clean :
# 	# $(MAKE) -C $(MLX_DIR) clean;
# 	# $(MAKE) -C $(LIBFT_DIR) clean;
# fclean : clean
# 	# $(MAKE) -C $(LIBFT_DIR) fclean;
# 	$(RM) $(NAME)
# re : fclean all

# run : re
# 	./$(NAME) scene.rt
# ppm : all
# 	./$(NAME) > result.ppm
# open : ppm
# 	open ./result.ppm
# $(NAME) : $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT)
# 	$(CC) $(CFLAG) $(LIB_FLAG) ./src/*.c ./src/*/*.c $(INCLUDE) -o $(NAME)
# 	install_name_tool -change $(MLX) $(MLX_DIR)/$(MLX) $(NAME)
# $(MLX_DIR)/$(MLX) :
# 	$(MAKE) -C $(MLX_DIR) all
# $(LIBFT_DIR)/$(LIBFT) :
# 	$(MAKE) -C $(LIBFT_DIR) all
# .PHONY : all clean re ppm open run