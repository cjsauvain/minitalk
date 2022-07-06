# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 12:04:13 by jsauvain          #+#    #+#              #
#    Updated: 2022/07/05 16:07:19 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_S = server.c get_bin.c

SRCS_C = client.c send_binaries.c

OBJS_S = $(SRCS_S:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

GCC = gcc

FLAGS = -Wall -Wextra -Werror -g3

NAME_S = server

NAME_C = client

RM = rm -f

CLR = clear

.c.o:
			$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME_S) $(NAME_C)
			make -C libft
			$(GCC) $(FLAGS) -Llibft -lft

$(NAME_S): $(OBJS_S)
			$(CLR)
			$(GCC) $(FLAGS) -o $(NAME_S) $(OBJS_S)

$(NAME_C): $(OBJS_C)
			$(GCC) $(FLAGS) -o $(NAME_C) $(OBJS_C)

clean:
			make clean -C libft
			$(RM) $(OBJS_S) $(OBJS_C)

fclean: clean
			make fclean -C libft
			$(RM) $(NAME_S) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
