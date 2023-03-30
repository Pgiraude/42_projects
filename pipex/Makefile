# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 19:14:58 by pgiraude          #+#    #+#              #
#    Updated: 2023/03/30 16:05:08 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c get_command.c prepare_fd.c

OBJS = $(SRC:.c=.o)

RM = rm -f

CC = cc

FLAGS = -Werror -Wextra -Wall

LIBFT = cd libft && make

MAKEFLAGS	=	--no-print-directory

$(NAME): $(OBJS)
	$(LIBFT) 
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a $(FLAGS)

all: $(NAME)

clean:
	$(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re