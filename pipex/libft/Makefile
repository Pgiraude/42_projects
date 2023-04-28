NAME    =   libft.a


SRCDIR	=	src/

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c	\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c	\
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c	\
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c	\
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c	\
		ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c	\
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c


SRC_PRINTFDIR	=	src/ft_printf/

SRC_PRINTF	=	ft_printf.c ft_convert_hex.c ft_convert_ptr.c \
				ft_len_calculator.c ft_convert_dec.c ft_convert_str.c ft_convert_udec.c


SRC_GNLDIR	=	src/get_next_line/

SRC_GNL		=	get_next_line.c get_next_line_utils.c get_next_line_bonus.c


SRC_OTHERSDIR	=	src/others/

SRC_OTHERS		=	ft_freestrings.c

OBJS    =   $(addprefix $(SRCDIR), $(SRC:.c=.o)) \
			$(addprefix $(SRC_PRINTFDIR), $(SRC_PRINTF:.c=.o)) \
			$(addprefix $(SRC_GNLDIR), $(SRC_GNL:.c=.o)) \
			$(addprefix $(SRC_OTHERSDIR), $(SRC_OTHERS:.c=.o))

RM  =   rm -f

MAKEFLAGS	=	--no-print-directory

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJS)
	ar  rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re