NAME    =   libft.a

SRC =   $(wildcard ft_*.c)

OBJS    =   $(SRC:.c=.o)

all: $(NAME)

RM  =   rm -f

WWW = -Werror -Wextra -Wall

CC = gcc

$(NAME):
	gcc -g3 $(WWW) -g3 -c $(SRC) -g3
	ar  rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all