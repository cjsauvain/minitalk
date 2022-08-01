# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 12:04:13 by jsauvain          #+#    #+#              #
#    Updated: 2022/08/01 11:42:21 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = -I srcs/libft -I includes

SRCS = srcs/mandatory/server.c srcs/mandatory/get_bin.c

SRCS_C = srcs/mandatory/client.c srcs/mandatory/send_bin.c \
		srcs/mandatory/check_errors.c

SRCB = srcs/bonus/server_bonus.c srcs/bonus/get_bin_bonus.c

SRCB_C = srcs/bonus/client_bonus.c srcs/bonus/send_bin_bonus.c \
		srcs/bonus/check_errors_bonus.c srcs/bonus/get_reception_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_C = $(SRCS_C:.c=.o)

OBJB = $(SRCB:.c=.o)

OBJB_C = $(SRCB_C:.c=.o)

GCC = gcc

FLAGS = -Wall -Wextra -Werror -g3

NAME = server

NAME_C = client

RM = rm -f

CLR = clear
ifdef	BONUS
			SRCS	=
			SRCS_C	=
			SRCS	+= $(SRCB)
			SRCS_C	+= $(SRCB_C)
endif

.c.o:
			$(GCC) $(FLAGS) $(INCLUDE) -c  $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_C)
		$(CLR)
		make -sC srcs/libft
		$(GCC) $(FLAGS) $(OBJS) $(INCLUDE) -Lsrcs/libft -lft -o $(NAME)
		$(GCC) $(FLAGS) $(OBJS_C) $(INCLUDE) -Lsrcs/libft -lft -o $(NAME_C)
			
bonus:	$(NAME)
		make BONUS=1

clean:
			make clean -sC srcs/libft
			$(RM) $(OBJS) $(OBJS_C) $(OBJB) $(OBJB_C)

fclean: clean
			make fclean -sC srcs/libft
			$(RM) $(NAME) $(NAME_C)

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re
