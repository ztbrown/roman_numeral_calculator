CFLAGS=-Wall -std=c99
CC=gcc
SOURCE=src/
TEST=test/

all: check

clean:
	rm -f *.a *.o roman

check: clean check_roman.o testRunner.o roman.o
	gcc -o tests check_roman.o testRunner.o -lcheck -pthread -lcheck_pic -lrt -lm -L. -lroman
	./tests

roman.o:
	${CC} ${CFLAGS} -c ${SOURCE}roman.c -o roman.o
	ar rcs libroman.a roman.o

check_roman.o: ${TEST}check_roman.h
	${CC} ${CFLAGS} -c ${TEST}check_roman.c -o check_roman.o

testRunner.o: ${TEST}check_roman.h
	${CC} ${CFLAGS} -c ${TEST}testRunner.c -o testRunner.o

valgrind:
	valgrind ./${SOURCE}roman
