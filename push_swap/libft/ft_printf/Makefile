# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:32:00 by pgiraude          #+#    #+#              #
#    Updated: 2023/03/17 13:32:01 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c ft_convert_hex.c ft_convert_ptr.c \
		ft_len_calculator.c ft_convert_dec.c ft_convert_str.c ft_convert_udec.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

RM = rm -f

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all