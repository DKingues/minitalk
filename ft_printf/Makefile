# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 16:29:45 by dicosta-          #+#    #+#              #
#    Updated: 2025/04/14 14:55:42 by dicosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c ft_print_format.c ft_print_digit.c ft_print_str.c \
	ft_print_hex.c ft_print_chr.c ft_print_ptr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:

	@rm -f $(OBJ)

fclean: clean

	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

