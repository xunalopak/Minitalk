# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchampli <rchampli@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 18:22:31 by rchampli          #+#    #+#              #
#    Updated: 2021/11/24 18:22:31 by rchampli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

SRC_SERVER = server.c \
			sc_utils.c

SRC_CLIENT = client.c \
			sc_utils.c \
			verif_pid.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -I 

RM = rm -f

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER) minitalk.h
			$(CC) -o $(SERVER) $(OBJ_SERVER)

$(CLIENT): $(OBJ_CLIENT) minitalk.h
			$(CC) -o $(CLIENT) $(OBJ_CLIENT)

clean:
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
		$(RM) $(SERVER) $(CLIENT)

re:   fclean all

.PHONY: all re clean fclean