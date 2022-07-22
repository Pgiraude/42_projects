NAME = printf.a
NAME2 = libft_cpy.a

SRC = ft_printf.c

OBJS = $(SRC:.c=.o)

#CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

RM = rm -f

$(NAME): $(OBJS)
	cd ./libft && $(MAKE)
	cp libft/libft.a $(NAME2)
	ar rcs $(NAME) $(OBJS)

clean:
	cd ./libft && $(MAKE) clean
	$(RM) $(OBJS)

fclean: clean
	cd ./libft && $(MAKE) fclean
	$(RM) $(NAME)
	$(RM) $(NAME2)

re: fclean all