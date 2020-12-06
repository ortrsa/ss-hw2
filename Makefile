FLAG= -Wall -g

all: main

main: main.o myBank.o
	gcc $(FLAG) -o main main.o myBank.o

main.o: main.c myBank.h
	gcc $(FLAG) -c main.c

myBank.o: myBank.c myBank.h
	gcc $(FLAG) -c myBank.c

.PHONY: clean all

clean:
	rm -f *.o main
