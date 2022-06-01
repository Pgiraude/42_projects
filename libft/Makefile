NAME    =   libft.a

SRC =   $(wildcard *.c)

OBJS    =   $(SRC:.c=.o)

all: $(NAME)

RM  =   rm -f

CC = gcc

$(NAME): $(OBJS)
	ar  rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

COMP:
	$(CC) 