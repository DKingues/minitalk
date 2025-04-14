# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/05 16:08:11 by vboxuser          #+#    #+#              #
#    Updated: 2025/04/14 18:00:57 by dicosta-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files

SERVER = server.c

CLIENT = client.c

LIBFT = cd libft && make

LIB = libft/libft.a

PRINTF = cd ft_printf && make

PRTF = ft_printf/libftprintf.a

# Sources and objects

SERVER_SRC = $(SERVER)

CLIENT_SRC = $(CLIENT)

SERVER_OBJ = $(SERVER_SRC:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<
	
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<
	
OBJS = $(CLIENT_OBJ) \
	$(SERVER_OBJ)

# Compiler

CC = cc

FLAGS = -Wall -Wextra -Werror

SERVER_NAME = server

CLIENT_NAME = client

NAME = server

# Messages

COMP_START = echo "\nCompilation starting...\n"

SERVER_READY = echo "\nThe server is ready.\n"

CLIENT_READY = echo "\nThe client is ready.\n"

CLEAN_DONE = echo "\nRemoved all the object files.\n"

FCLEAN_DONE = echo "\nRemoved all objects and executables.\n"

# Rules

all: $(NAME)

$(NAME): comp_start ft_server ft_client

comp_start:
	@$(COMP_START)
	@$(LIBFT)
	@$(PRINTF)
	
ft_server: $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIB) $(PRTF) -o $(SERVER_NAME)
	$(SERVER_READY)

ft_client: $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIB) $(PRTF) -o $(CLIENT_NAME)
	$(CLIENT_READY)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@cd ft_printf && make clean
	$(CLEAN_DONE)

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean
	$(FCLEAN_DONE)

re: fclean all

.PHONY: all minitalk server client clean fclean re libft




