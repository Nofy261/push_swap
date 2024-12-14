# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nolecler <nolecler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/30 08:12:18 by nolecler          #+#    #+#              #
#    Updated: 2024/12/14 14:18:05 by nolecler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

FSRCS = push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		utils.c \
		utils2.c \
		main.c \
		parsing.c \
		split.c \
		sort.c \
		sort_bis.c \
		# main_of_test.c
		


OFILES = $(FSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	$(CC) $(OFILES) -o $(NAME)

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)
	
re : fclean $(NAME)

.PHONY: all clean fclean re 