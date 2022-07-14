SRCS = ft_printf.c ft_putnbr.c low_hexa.c up_hexa.c put_hexa_ptr.c to_find.c \
		ft_putstr.c ft_putchar.c ft_format.c

GCC = gcc

FLAGS = -Wall -Wextra -Werror -g3

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

RM = rm -f

AR = ar rcs

all: $(NAME)

clean:
		${RM} $(OBJS) ${BONUS}

.c.o:
		${GCC} ${FLAGS} -c $< -o ${<:.c=.o}

fclean: clean
		${RM} $(NAME)

$(NAME): ${OBJS}
		${AR} $(NAME) ${OBJS}

re: fclean all

.PHONY: all clean fclean re
