CC = clang
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

NAME = pathfinder

all: $(NAME)

$(NAME): src/*.c
	cd libmx && make
	mkdir -p obj
	cd obj && $(CC) $(CCFLAGS) -c ../src/*.c -I../inc -I../libmx/inc
	$(CC) -o $(NAME) obj/*.o -Llibmx -lmx

clean:
	rm -rf obj
	make -C libmx clean

uninstall: clean
	rm -rf $(NAME)
	make -C libmx uninstall

reinstall: uninstall $(NAME)

