# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 16:49:07 by pgiraude          #+#    #+#              #
#    Updated: 2023/05/02 13:28:26 by pgiraude         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRC_DIR 	=	src/

SRC 	=	so_long.c


OBJS 	=	$(addprefix $(SRC_DIR), $(SRC:.c=.o))


RM 		=	rm -f

CFLAGS	=	-Werror -Wextra -Wall #-g3 #-fsanitize=address

CC 		=	cc

MLX 	=	cd minilibx-linux && make

#%.o: %.c
#	$(CC) $(FLAGS) $(OBJS) -Iminilibx-linux -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MLX)
	$(CC) $(FLAGS) $(OBJS) -Iminilibx-linux -Lminilibx-linux -lmlx -lm -lXext -lX11 -o $(NAME)


#$(NAME): $(OBJS)a
#	$(MLX)
#	$(CC) $(CFLAGS) $(OBJS)  ./minilibx-linux/libmlx_linux.a ./minilibx-linux/libmlx. -Lmlx -lmlx -lm -lXext -lX11 -o $(NAME)



clean:
	$(MLX) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re

#(NAME): $(OBJS) $(HEADER)
#		$(MAKE) -C $(MLX_DIR)
#		${CC} ${CFLAGS} ${SRCS} -I mlx -Lmlx -lmlx -lm -lXext -lX11 -o ${NAME} 
#%.o: %.c $(HEADER)
#	$(CC) $(CFLAGS) -I $(MLX_DIR) -o $@ -c $< 