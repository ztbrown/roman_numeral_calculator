CFLAGS=-Wall -std=c99
CC=gcc
SOURCE=src/
TEST=test/

all: check

clean:
	rm -f *.a *.o roman tests

check: clean check_to_arabic.o check_from_arabic.o check_calculator.o check_validator.o testRunner.o roman.o
	gcc -o tests check_to_arabic.o check_from_arabic.o check_calculator.o check_validator.o calculator.o validator.o converter.o testRunner.o -lcheck -pthread -lcheck_pic -lrt -lm -L. -lroman
	./tests

roman.o: converter.o calculator.o validator.o
	${CC} ${CFLAGS} -c ${SOURCE}roman.c -o roman.o
	ar rcs libroman.a roman.o

converter.o:
	${CC} ${CFLAGS} -c ${SOURCE}converter.c -o converter.o

calculator.o:
	${CC} ${CFLAGS} -c ${SOURCE}calculator.c -o calculator.o

validator.o:
	${CC} ${CFLAGS} -c ${SOURCE}validator.c -o validator.o

check_to_arabic.o:
	${CC} ${CFLAGS} -c ${TEST}check_to_arabic.c -o check_to_arabic.o

check_from_arabic.o:
	${CC} ${CFLAGS} -c ${TEST}check_from_arabic.c -o check_from_arabic.o

check_calculator.o:
	${CC} ${CFLAGS} -c ${TEST}check_calculator.c -o check_calculator.o

check_validator.o:
	${CC} ${CFLAGS} -c ${TEST}check_validator.c -o check_validator.o

testRunner.o:
	${CC} ${CFLAGS} -c ${TEST}testRunner.c -o testRunner.o

valgrind:
	valgrind ./${SOURCE}roman
