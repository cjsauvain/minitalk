# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 12:04:13 by jsauvain          #+#    #+#              #
#    Updated: 2022/07/08 09:56:29 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = server.c get_bin.c

SRCS_C = client.c send_binaries.c

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
			make -sC libft
			$(GCC) $(FLAGS) -o $(NAME) $(OBJS) -Llibft -lft
			$(GCC) $(FLAGS) -o $(NAME_C) $(OBJS_C) -Llibft -lft
			
clean:
			make clean -sC libft
			$(RM) $(OBJS) $(OBJS_C)

fclean: clean
			make fclean -sC libft
			$(RM) $(NAME) $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
