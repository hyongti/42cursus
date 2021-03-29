CC = gcc
NAME = libasm.a
NASM = nasm
AFLAGS = -f macho64
INCLUDE = -I./include/

SRCS_NAME = ft_strlen.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_strdup.s \
			ft_write.s \
			ft_read.s
SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NAME))

OBJS = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(AFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

