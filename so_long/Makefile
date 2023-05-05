# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 16:49:07 by pgiraude          #+#    #+#              #
#    Updated: 2023/05/05 14:41:39 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC_DIR 	=	src/

SRC 	=	so_long.c error_manager.c check_map.c


OBJS 	=	$(addprefix $(SRC_DIR), $(SRC:.c=.o))


RM 		=	rm -f

CFLAGS	=	-Werror -Wextra -Wall #-g3 #-fsanitize=address

CC 		=	cc

MLX 	=	cd minilibx-linux && make

LIBFT	=	cd libft && make

#%.o: %.c
#	$(CC) $(FLAGS) $(OBJS) -Iminilibx-linux -O3 -c $< -o $@

all: $(NAME)

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

fclean: clean
	$(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re

#(NAME): $(OBJS) $(HEADER)
#		$(MAKE) -C $(MLX_DIR)
#		${CC} ${CFLAGS} ${SRCS} -I mlx -Lmlx -lmlx -lm -lXext -lX11 -o ${NAME} 
#%.o: %.c $(HEADER)
#	$(CC) $(CFLAGS) -I $(MLX_DIR) -o $@ -c $< 