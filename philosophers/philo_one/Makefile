NAME = philo_one
CC = gcc
CFLAGS = -fsanitize=address #-Wall -Wextra -Werror
INCLUDE = -I./include

SRCS_NAME = main.c \
		parse.c \
		utils/ft_atoi.c \
		utils/get_time.c
SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDE)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re