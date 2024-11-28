NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

FSRCS =


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