# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 16:49:07 by pgiraude          #+#    #+#              #
#    Updated: 2023/05/17 16:59:51 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

NAME_2	= test

SRC_DIR 	=	src/

SRC 	=	so_long.c error_manager.c check_map_conformity.c check_map_paths.c hook_events.c

TEST	=	test.c error_manager.c check_map_conformity.c check_map_paths.c hook_events.c

OBJS 	=	$(addprefix $(SRC_DIR), $(SRC:.c=.o))

OB_TEST =	$(addprefix $(SRC_DIR), $(TEST:.c=.o))

RM 		=	rm -f

CFLAGS	=	-Werror -Wextra -Wall #-g3 #-fsanitize=address

CC 		=	cc

MLX 	=	cd minilibx-linux && make

LIBFT	=	cd libft && make

#%.o: %.c
#	$(CC) $(FLAGS) $(OBJS) -Iminilibx-linux -O3 -c $< -o $@

all: $(NAME)

test: $(NAME_2)

$(NAME_2): $(OB_TEST)
	$(LIBFT)
	$(MLX)
	$(CC) $(FLAGS) $(OB_TEST) ./libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lm -lXext -lX11 -o $(NAME_2)

$(NAME): $(OBJS)
	$(LIBFT)
	$(MLX)
	$(CC) $(FLAGS) $(OBJS) ./libft/libft.a -Iminilibx-linux -Lminilibx-linux -lmlx -lm -lXext -lX11 -o $(NAME)


#$(NAME): $(OBJS)a
#	$(MLX)
#	$(CC) $(CFLAGS) $(OBJS)  ./minilibx-linux/libmlx_linux.a ./minilibx-linux/libmlx. -Lmlx -lmlx -lm -lXext -lX11 -o $(NAME)



clean:
	$(LIBFT) clean
	$(MLX) clean
	$(RM) $(OBJS)
	$(RM) $(OB_TEST)

fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_2)

re: fclean all
	
.PHONY: all clean fclean test re

#(NAME): $(OBJS) $(HEADER)
#		$(MAKE) -C $(MLX_DIR)
#		${CC} ${CFLAGS} ${SRCS} -I mlx -Lmlx -lmlx -lm -lXext -lX11 -o ${NAME} 
#%.o: %.c $(HEADER)
#	$(CC) $(CFLAGS) -I $(MLX_DIR) -o $@ -c $< 