NAME = animal0

CC = c++

RM = rm -f

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Animal.cpp main.cpp Cat.cpp Dog.cpp \
		WrongAnimal.cpp WrongCat.cpp \
		Brain.cpp

HEADER = Animal.hpp Cat.hpp Dog.hpp \
		WrongAnimal.hpp WrongCat.hpp \
		Brain.hpp

OBJS = $(SRC:.cpp=.o)

%.o: %.cpp	$(HEADER)
	$(CC) -g $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

