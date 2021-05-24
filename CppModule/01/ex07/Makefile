NAME = replace
CC = clang++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
SRCS = main.cpp \
		Replace.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(VERSION) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
