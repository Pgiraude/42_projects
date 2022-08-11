NAME = libftprintf.a

SRC = ft_printf.c ft_convert_hex_len.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

RM = rm -f

$(NAME): $(OBJS)
	cd ./libft && $(MAKE)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	cd ./libft && $(MAKE) clean
	$(RM) $(OBJS)

fclean: clean
	cd ./libft && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all