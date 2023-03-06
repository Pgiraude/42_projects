NAME = push_swap.a

SRC = push_swap.c src/check_error.c src/print_piles.c src/quick_sort.c src/free_dlist.c src/move.c src/utils_chainlist.c \
		algo_1step.c


SRC_CHAIN = chainlist/chainlist.c

OBJS = $(SRC:.c=.o) $(SRC_CHAIN:.c=.o)

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	cd libft && $(MAKE)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	cd libft && $(MAKE) clean
	$(RM) $(OBJS)

fclean: clean
	cd libft && $(MAKE) fclean
	$(RM) $(NAME)

re: fclean all