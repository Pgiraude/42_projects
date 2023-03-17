# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:31:05 by pgiraude          #+#    #+#              #
#    Updated: 2023/03/17 13:31:07 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libft.a

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c	\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c	\
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c	\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c	\
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c	\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c	\
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c

SRC_GNL =	get_next_line/get_next_line_v2.c get_next_line/get_next_line_utils.c

OBJS    =   $(SRC:.c=.o) $(SRC_GNL:.c=.o)

all: $(NAME)

RM  =   rm -f

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJS)
	cd ./ft_printf && $(MAKE)
	cp ft_printf/libftprintf.a $(NAME)
	ar  rcs $(NAME) $(OBJS)

clean:
	cd ./ft_printf && $(MAKE) clean
	$(RM) $(OBJS)

fclean: clean
	cd ./ft_printf && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all