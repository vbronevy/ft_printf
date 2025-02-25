# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: vbronevy <vbronevy@student.42.fr>          #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2025-01-28 17:39:26 by vbronevy          #+#    #+#             #
#   Updated: 2025-01-28 17:39:26 by vbronevy         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC = cc

CFLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a

SRCS = ft_printf.c functions.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re