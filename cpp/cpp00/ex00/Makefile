NAME = megaphone

CC = c++

CPPFLAGS	=	-Werror -Wextra -Wall -std=c++98 #-pedantic-errors

SRC = megaphone.cpp

OBJS	=	$(SRC:.cpp=.o)

%.o : %.cpp
	${CC} ${CPPFLAGS} -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re