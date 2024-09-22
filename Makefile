CC ?= gcc
RM ?= rm -f
MAKE = make

OBJ_DIR = ./build
INCLUDE_DIR = ./include/
LIB_INCLUDE_DIR = ./lib/include/
SRC_DIR = ./source
LIB_DIR = ./lib/

MAIN = $(SRC_DIR)/main.c
SRC = $(filter-out $(MAIN), $(wildcard $(SRC_DIR)/*.c))

MAIN_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(MAIN))
SRC_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

NAME = binary

CFLAGS = -Wall -Wextra --std=gnu11
CPPFLAGS = -iquote $(INCLUDE_DIR) -iquote $(LIB_INCLUDE_DIR)
LDFLAGS = -L$(LIB_DIR) -lmy
DEBUGFLAGS = -ggdb3

all: $(NAME)

$(NAME): $(MAIN_OBJ) $(SRC_OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(MAIN_OBJ) $(SRC_OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) \
	-o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(RM) $(OBJ_DIR)/*.o vgcore*

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	$(RM) $(NAME)

debug: CFLAGS += -ggdb3
debug: fclean all

re: fclean all

PHONY: clean fclean debug
