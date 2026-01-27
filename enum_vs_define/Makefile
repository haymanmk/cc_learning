.PHONY: all clean

CC_FLAGS = -Wall -g -O0

all: main

main: main.o
	gcc $(CC_FLAGS) -o main main.o

main.o: main.c config.h
	gcc $(CC_FLAGS) -c main.c
	gcc -E main.c -o main.preproc

clean:
	rm -f main *.o *.preproc