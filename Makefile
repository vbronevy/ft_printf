
NAME    = libftprintf.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_printf.c ft_printf_helper.c
OBJS    = ft_printf.o ft_printf_helper.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

ft_printf.o: ft_printf.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_printf.c -o ft_printf.o

ft_printf_helper.o: ft_printf_helper.c ft_printf.h
	$(CC) $(CFLAGS) -c ft_printf_helper.c -o ft_printf_helper.o

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
