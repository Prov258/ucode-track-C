CC = clang
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:%.c=%.o))

LIB_DIR = libmx
LIB = libmx.a

NAME = pathfinder

.PHONY: all clean uninstall reinstall

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $^ -L $(LIB_DIR) -lmx

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CCFLAGS) -c $^ -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -o $@

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

uninstall: clean
	rm -rf $(NAME)
	make -C $(LIB_DIR) uninstall

reinstall: uninstall $(NAME)

