all: exemplo.o
	gcc exemplo.o main.c -o main

exemplo.o:	exemplo.h
	gcc -c exemplo.c

clean:
	rm -rf *.o

run: 
	./main