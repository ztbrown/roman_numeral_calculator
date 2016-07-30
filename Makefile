CFLAGS=-Wall -std=c99
CC=gcc
SOURCE=src/
TEST=test/

all: check

clean:
	rm -f *.a *.o roman tests

check: clean check_to_arabic.o check_from_arabic.o testRunner.o roman.o
	gcc -o tests check_to_arabic.o check_from_arabic.o converter.o testRunner.o -lcheck -pthread -lcheck_pic -lrt -lm -L. -lroman
	./tests

roman.o: converter.o
	${CC} ${CFLAGS} -c ${SOURCE}roman.c -o roman.o
	ar rcs libroman.a roman.o

converter.o: ${SOURCE}converter.h
	${CC} ${CFLAGS} -c ${SOURCE}converter.c -o converter.o

check_to_arabic.o: ${TEST}check_to_arabic.h
	${CC} ${CFLAGS} -c ${TEST}check_to_arabic.c -o check_to_arabic.o

check_from_arabic.o: ${TEST}check_from_arabic.h
		${CC} ${CFLAGS} -c ${TEST}check_from_arabic.c -o check_from_arabic.o

testRunner.o: ${TEST}check_to_arabic.h ${SOURCE}converter.h
	${CC} ${CFLAGS} -c ${TEST}testRunner.c -o testRunner.o

valgrind:
	valgrind ./${SOURCE}roman
