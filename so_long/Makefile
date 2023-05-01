# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 16:49:07 by pgiraude          #+#    #+#              #
#    Updated: 2023/05/01 19:27:39 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC_DIR 	=	src/



SRC 	=	so_long.c

OBJS 	=	$(addprefix $(SRC_DIR), $(SRC:.c=.o))

RM 		=	rm -f

CFLAGS	=	-Werror -Wextra -Wall

CC 		=	cc

$(NAME): $(OBJS)
	$(CC) -o $(CFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	
.PHONY: all clean fclean