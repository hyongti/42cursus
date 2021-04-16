NAME = phonebook
CC = clang++
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./

SRCS =	main.cpp \
		contact.cpp \
		phonebook.cpp
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)