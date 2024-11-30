# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 08:12:18 by nolecler          #+#    #+#              #
#    Updated: 2024/11/30 09:16:47 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

FSRCS = push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		push.c \


OFILES = $(FSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
		 $(NAME) $(OFILES)

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)
	
re : fclean $(NAME)

.PHONY: all clean fclean re 