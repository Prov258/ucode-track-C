CC = clang
CCFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

LIB_NAME = libmx.a

all: LIBMX

LIBMX: src/*.c
	mkdir -p obj
	cd obj && $(CC) $(CCFLAGS) -c ../src/*.c
	ar -rcs $(LIB_NAME) obj/*.o

clean:
	rm -rf obj

uninstall: clean
	rm -rf $(LIB_NAME)

reinstall: uninstall LIBMX

