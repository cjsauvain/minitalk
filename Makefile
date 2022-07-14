# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 12:04:13 by jsauvain          #+#    #+#              #
#    Updated: 2022/07/14 16:54:36 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c get_bin.c server_utils.c

SRCS_C = client.c send_binaries.c client_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

GCC = gcc

FLAGS = -Wall -Wextra -Werror -g3

NAME = server

NAME_C = client

RM = rm -f

CLR = clear

.c.o:
			$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_C)
			$(CLR)
			make -sC ft_printf
			$(GCC) $(FLAGS) -o $(NAME) -L. $(OBJS) -Lft_printf -lftprintf
			$(GCC) $(FLAGS) -o $(NAME_C) $(OBJS_C)
			
clean:
			make clean -sC ft_printf
			$(RM) $(OBJS) $(OBJS_C)

fclean: clean
			make fclean -sC ft_printf
			$(RM) $(NAME) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
