NAME = push_swap.a

SRC				= src/push_swap.c src/check_error.c src/print_piles.c src/quick_sort.c 

SRC_MOVE		= src/move/move.c src/move/move_all.c

SRC_CHAINLIST 	= src/chainlist/chainlist.c src/chainlist/chainlist_copy_free.c \
				src/chainlist/chainlist_insert_cell.c

SRC_ALGORITHM 	= src/algorithm/get_all_cost.c src/algorithm/push_to_b_optimisation.c \
				src/algorithm/get_swap_optimisation.c src/algorithm/is_aligned.c \
				src/algorithm/place_target.c src/algorithm/push_to_a.c \
				src/algorithm/push_to_b.c

OBJS = $(SRC:.c=.o) $(SRC_CHAINLIST:.c=.o) $(SRC_MOVE:.c=.o) $(SRC_ALGORITHM:.c=.o)

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

.PHONY: all clean fclean re