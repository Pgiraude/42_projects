# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 19:14:58 by pgiraude          #+#    #+#              #
#    Updated: 2023/04/06 17:54:14 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_B = pipex_bonus

SRC = pipex.c get_command.c utils.c openfile.c

SRC_B = pipex.c get_command.c utils.c openfile_bonus.c

OBJS = $(SRC:.c=.o)

OBJS_B = $(SRC_B:.c=.o)

RM = rm -f

CC = cc

FLAGS = -Werror -Wextra -Wall

LIBFT = cd libft && make

MAKEFLAGS	=	--no-print-directory

$(NAME): $(OBJS)
	$(LIBFT) 
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a $(FLAGS)

$(NAME_B): $(OBJS_B)
	$(LIBFT) 
	$(CC) -o $(NAME_B) $(OBJS_B) ./libft/libft.a $(FLAGS)

all: $(NAME)

bonus: $(NAME_B)

clean:
	$(LIBFT) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)

fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re