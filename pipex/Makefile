NAME = pipex

SRC = pipex.c

OBJS = $(SRC:.c=.o)

RM = rm -f

CC = cc

FLAGS = -Werror -Wextra -Wall

LIBFT = cd libft && make

MAKEFLAGS	=	--no-print-directory

$(NAME): $(OBJS)
	$(LIBFT) 
	$(CC) -o $(NAME) $(OBJS) ./libft/libft.a $(FLAGS)

all: $(NAME)

clean:
	$(LIBFT) clean
	$(RM) $(OBJS)

fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re