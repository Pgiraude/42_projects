NAME =	philo

SRC	=	philo.c error_manager.c init_philo.c \
		launch_philo.c exit_philo.c utils_philo.c

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-Werror -Wextra -Wall 

CC	=	cc

RM	=	rm -f

$(NAME): $(OBJ)
	$(CC) -g $(FLAGS) -pthread $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
