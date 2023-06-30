# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 19:14:58 by pgiraude          #+#    #+#              #
#    Updated: 2023/06/30 10:43:50 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = src/openfile.c

SRC_B = bonus/openfile_bonus.c

SRC_UTILS = src/get_command.c src/utils.c src/error_manager.c src/pipex.c

OBJS = $(SRC:.c=.o) $(SRC_UTILS:.c=.o)

OBJS_B = $(SRC_B:.c=.o) $(SRC_UTILS:.c=.o)

HEADER	=	include/pipex.h

RM = rm -f

CC = cc

CFLAGS = -Werror -Wextra -Wall

LIBFT = cd libft && make

MAKEFLAGS	=	--no-print-directory

%.o : %.c ${HEADER}
	${CC} ${CFLAGS} -o $@ -c $<


$(NAME): $(OBJS)
	$(LIBFT) 
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a $(FLAGS)

all: $(NAME)

bonus: $(OBJS_B)
	$(LIBFT)
	$(CC) -o $(NAME) $(OBJS_B) ./libft/libft.a $(FLAGS)
	$(RM) src/openfile.o


clean:
	$(LIBFT) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re