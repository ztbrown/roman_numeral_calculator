CFLAGS=-Wall -g
CC=gcc

all: clean roman

roman: src/roman.c
	${CC} ${CFLAGS} src/roman.c -o src/roman

clean:
	rm -f src/*.o src/roman

valgrind: roman
	valgrind ./src/roman
