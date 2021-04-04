NAME = philo_one
CC = gcc
CFLAGS = -g3 -fsanitize=address #-Wall -Wextra -Werror
INCLUDE = -I./include

SRCS_NAME = 1_main.c \
		2_is_valid_argument.c \
		3_parse_argument.c \
		4_prepare_for_simulation.c \
		5_start_simulation.c \
		6_simulation.c \
		7_print_message.c \
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