# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 16:54:35 by aelousse          #+#    #+#              #
#    Updated: 2021/12/14 20:05:42 by aelousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = minitalk_bonus.h

SERVER_SRCS = server_bonus.c minitalk_utils_bonus.c
CLIENT_SRCS = client_bonus.c minitalk_utils_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: bonus

bonus:$(CLIENT_OBJS) $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o client
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -o server
	@echo "Server Created Successfully"
	@echo "Client Created Successfully"

%.o:%.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) client server
	@echo "Client & Server Removed Successfully"
