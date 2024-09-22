STD_FUNCS = ./my_stdlib/free.c \
						./my_stdlib/alloc.c \
						./my_stdlib/alloc_tracker.c

STRINGS_FUNCS = ./my_string/my_memcpy.c

SRC = $(STRINGS_FUNCS) \
	   	$(STD_FUNCS)

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
