NAME = philo_two
CC = gcc
CFLAGS = #-g3 -fsanitize=address #-Wall -Wextra -Werror
INCLUDE = -I./include

SRCS_NAME = main.c \
		is_valid_argument.c \
		parse_argument.c \
		prepare_for_simulation.c \
		start_simulation.c \
		simulation.c \
		print_message.c \
		clean.c \
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