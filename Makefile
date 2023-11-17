CC = cc
CFLAGS = -Wextra -Werror -Wall
NAME = libftprintf.a
SRC = ft_print_number.c ft_printf.c ft_strlen.c ft_putchar.c  ft_base.c ft_pointer.c ft_putstr.c ft_unsigned.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o : %.c ft_printf.h
	cc $(CFLAGS) -c $<

fclean: clean
	rm -rf $(NAME)

clean :
	rm -rf $(OBJ)

.PHONY : all clean fclean re
