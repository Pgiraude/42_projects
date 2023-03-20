# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 11:03:41 by pgiraude          #+#    #+#              #
#    Updated: 2023/03/18 17:43:15 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRC		=	pipex.c

OBJS	=	$(SRC:.c=.0)

CC		= cc

CFLAGS	= -Werror -Wextra -Wall

all:	$(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)