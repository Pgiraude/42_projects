NAME    =   libft.a

SRC =   $(wildcard *.c)

OBJS    =   $(SRC:.c=.o)

all: $(NAME)

RM  =   rm -f

WWW = -Werror -Wextra -Wall

CC = gcc

$(NAME):
	gcc $(WWW) -c $(SRC)
	ar  rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all