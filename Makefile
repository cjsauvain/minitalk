# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 12:04:13 by jsauvain          #+#    #+#              #
#    Updated: 2022/07/20 09:15:55 by jsauvain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = mandatory/server.c mandatory/get_bin.c mandatory/server_utils.c

SRCS_C = mandatory/client.c mandatory/send_binaries.c mandatory/client_utils.c

SRCB = bonus/server_bonus.c bonus/get_bin_bonus.c bonus/server_utils_bonus.c

SRCB_C = bonus/client_bonus.c bonus/send_binaries_bonus.c bonus/client_utils_bonus.c \
		bonus/get_reception_bonus.c

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

.c.o:
			$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_C)
			$(CLR)
			make -sC ft_printf
			$(GCC) $(FLAGS) -o $(NAME) -Lmandatory $(OBJS) -Lft_printf -lftprintf
			$(GCC) $(FLAGS) -o $(NAME_C) $(OBJS_C)
			
bonus:	$(OBJB) $(OBJB_C)
		$(CLR)
		make -sC ft_printf
		$(GCC) $(FLAGS) -o $(NAME) -Lbonus $(OBJB) -Lft_printf -lftprintf
		$(GCC) $(FLAGS) -o $(NAME_C) -Lbonus $(OBJB_C) -Lft_printf -lftprintf

clean:
			make clean -sC ft_printf
			$(RM) $(OBJS) $(OBJS_C) $(OBJB) $(OBJB_C)

fclean: clean
			make fclean -sC ft_printf
			$(RM) $(NAME) $(NAME_C)

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re
