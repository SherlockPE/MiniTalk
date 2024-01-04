# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:26:31 by flopez-r          #+#    #+#              #
#    Updated: 2024/01/04 15:46:25 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRC_SERVER =	src/server.c
SRC_CLIENT =	src/client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)


CC := gcc
CFLAGS := -Wall -Wextra -Werror
# INCLUDE_FLAG := -ILibft/ -Isrc/ -ILibft/printf/

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_SERVER) -L./Libft -lft -o $@
# $(CC) $(CFLAGS) $(INCLUDE_FLAG) $(OBJ_SERVER) -L./Libft -lft -o $@

$(CLIENT): $(OBJ_CLIENT)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -L./Libft -lft -o $@
# $(CC) $(CFLAGS) $(INCLUDE_FLAG) $(OBJ_CLIENT) -L./Libft -lft -o $@

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(SERVER)
	rm -f $(CLIENT)

re:	fclean all

.PHONY: all clean fclean re

