# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 19:14:58 by pgiraude          #+#    #+#              #
#    Updated: 2023/04/11 16:30:05 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = src/pipex.c  src/openfile.c

SRC_B = bonus/pipex_bonus.c bonus/openfile_bonus.c

SRC_UTILS = src/get_command.c src/utils.c

OBJS = $(SRC:.c=.o) $(SRC_UTILS:.c=.o)

OBJS_B = $(SRC_B:.c=.o) $(SRC_UTILS:.c=.o)

#OBJS_UTILS = $(SRC_UTILS:.c=.o)

RM = rm -f

CC = cc

FLAGS = -Werror -Wextra -Wall

LIBFT = cd libft && make

MAKEFLAGS	=	--no-print-directory

$(NAME): $(OBJS)
	$(LIBFT) 
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a $(FLAGS)

all: $(NAME)

#bonus: openfile_bonus.o $(filter-out openfile.o, $(OBJS))

#bonus:
#	$(CC) -c openfile_bonus.c
#	mv openfile_bonus.o openfile.o
#	$(LIBFT) 
#	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a $(FLAGS)

bonus: $(OBJS_B)
	$(LIBFT)
	$(CC) -o $(NAME) $(OBJS_B) ./libft/libft.a $(FLAGS)
	$(RM) openfile.o
	$(RM) pipex.o

clean:
	$(LIBFT) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)


fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re