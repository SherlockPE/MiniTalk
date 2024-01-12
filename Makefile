# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flopez-r <flopez-r@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/04 13:26:31 by flopez-r          #+#    #+#              #
#    Updated: 2024/01/12 16:19:00 by flopez-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRC_SERVER =	src/server.c
SRC_CLIENT =	src/client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER_BONUS =	src/bonus_server.c
SRC_CLIENT_BONUS =	src/bonus_client.c
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

CC := gcc
CFLAGS := -Wall -Wextra -Werror

#Mandatory part
all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_SERVER) -L./Libft -lft -o $@

$(CLIENT): $(OBJ_CLIENT)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -L./Libft -lft -o $@

#Bonus part
bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_SERVER_BONUS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -L./Libft -lft -o $@

$(CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -L./Libft -lft -o $@

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SERVER_BONUS)
	rm -f $(OBJ_CLIENT_BONUS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(SERVER)
	rm -f $(CLIENT)
	rm -f $(SERVER_BONUS)
	rm -f $(CLIENT_BONUS)

re:	fclean all

.PHONY: all clean fclean re


# INCLUDE_FLAG := -ILibft/ -Isrc/ -ILibft/printf/
# $(CC) $(CFLAGS) $(INCLUDE_FLAG) $(OBJ_SERVER) -L./Libft -lft -o $@
# $(CC) $(CFLAGS) $(INCLUDE_FLAG) $(OBJ_CLIENT) -L./Libft -lft -o $@