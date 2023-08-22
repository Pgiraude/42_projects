NAME = megaphone

CC = c++

CFLAGS	=	-Werror -Wextra -Wall -std=c++98 #-pedantic-errors


SRC = megaphone.cpp

OBJ	=	$(SRC:.cpp=.o)


%.o : %.cpp #${HEADER}
	${CC} ${CFLAGS} -o $@ -c $<

all : $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re