NAME = printf.a

SRC = ft_printf.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

re: fclean all