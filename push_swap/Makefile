NAME = push_swap.a

SRC = 	push_swap.c check_error.c print_piles.c quick_sort.c free_dlist.c move.c \
		utils_chainlist.c algo.c

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