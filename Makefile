NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

FSRCS = 


OFILES = $(FSRCS:.c=.o)

ARRC=ar -rc

all : $(NAME)

$(NAME) : $(OFILES)
		$(ARRC) $(NAME) $(OFILES)

clean :
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)
	
re : fclean $(NAME)

.PHONY: all clean fclean re 