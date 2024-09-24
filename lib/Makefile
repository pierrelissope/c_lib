SRC = $(shell find . -name "*.c")

CFLAGS = -Wall -Wextra
CPPFLAGS = -iquote .
OBJ = $(SRC:.c=.o)
NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f ../../$(NAME)

debug: CFLAGS += -ggdb3
debug: all

re:	fclean
	all

.PHONY: all clean fclean re
