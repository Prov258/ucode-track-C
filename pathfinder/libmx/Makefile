CC = clang
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:%.c=%.o))

NAME = libmx

LIB_NAME = libmx.a

.PHONY: all clean uninstall reinstall

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(LIB_NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $^ -o $@

clean:
	rm -rf obj

uninstall: clean
	rm -rf $(LIB_NAME)

reinstall: uninstall LIBMX

