# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 16:49:07 by pgiraude          #+#    #+#              #
#    Updated: 2023/05/28 20:30:29 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC_DIR 	=	src/

SRC 	=	so_long.c error_manager.c check_map_conformity.c check_map_paths.c \
			solong_utils.c get_images.c hook_events.c

OBJS 	=	$(addprefix $(SRC_DIR), $(SRC:.c=.o))

RM 		=	rm -f

CFLAGS	=	-Werror -Wextra -Wall

CC 		=	cc

MLX 	=	cd minilibx-linux && make

LIBFT	=	cd libft && make

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBFT)
	$(MLX)
	$(CC) $(FLAGS) $(OBJS) ./libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lm -lXext -lX11 -o $(NAME)

clean:
	$(LIBFT) clean
	$(MLX) clean
	$(RM) $(OBJS)

fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re