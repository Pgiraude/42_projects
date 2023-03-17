# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:30:36 by pgiraude          #+#    #+#              #
#    Updated: 2023/03/17 13:30:39 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

B_NAME	= checker

SRC				= src/push_swap.c src/main.c

SRC_MOVE		= src/move/move.c src/move/move_all.c

SRC_CHAINLIST 	= src/chainlist/chainlist.c src/chainlist/chainlist_copy_free.c \
				src/chainlist/chainlist_insert_cell.c

SRC_ALGORITHM 	= src/algorithm/get_all_cost.c src/algorithm/get_cost_utils.c \
				src/algorithm/push_to_b_optimisation.c src/algorithm/get_swap_optimisation.c \
				src/algorithm/is_aligned.c src/algorithm/place_target.c \
				src/algorithm/push_to_a.c src/algorithm/push_to_b.c

SRC_PRINT_MOVE	= src/print_move/print_move.c

SRC_SET_UP		= src/set_up/check_error.c src/set_up/quick_sort.c \
				src/set_up/get_values.c src/set_up/set_up.c

B_SRC			= bonus/push_swap_bonus.c src/algorithm/is_aligned.c
				


OBJS =	$(SRC:.c=.o) $(SRC_CHAINLIST:.c=.o) $(SRC_MOVE:.c=.o) $(SRC_ALGORITHM:.c=.o) \
		$(SRC_SET_UP:.c=.o) $(SRC_PRINT_MOVE:.c=.o)

B_OBJS =	$(B_SRC:.c=.o) $(SRC_CHAINLIST:.c=.o) $(SRC_MOVE:.c=.o) $(SRC_SET_UP:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LIBFT = cd libft && make

RM = rm -f

CC = cc

all: $(NAME) $(B_NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS)
	$(LIBFT)
	$(CC) -g -o $(B_NAME) $(B_OBJS) ./libft/libft.a $(CFLAGS)

$(NAME): $(OBJS)
	$(LIBFT)
	$(CC) -g -o $(NAME) $(OBJS) ./libft/libft.a $(CFLAGS)

clean:
	cd libft && $(MAKE) clean
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)

fclean: clean
	cd libft && $(MAKE) fclean
	$(RM) $(NAME)
	$(RM) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re