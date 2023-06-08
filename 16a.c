#ifndef exemplo.h
#define exemplo.h

// Declaração de uma função
int somar(int a, int b);

// Definição de uma constante
#define PI 3.14159

#endif // exemplo


#include <stdio.h>
#include "exemplo.h" // Inclui o cabeçalho criado

int somar(int a, int b) {
    return a + b;
}

int main() {
    int num1 = 5;
    int num2 = 3;
    int resultado = somar(num1, num2);

    printf("A soma de %d e %d é: %d\n", num1, num2, resultado);

    return 0;
}

#include "exemplo.h"


int somar( int a , int b){
    
return(a+b);
}



all: exemplo.o
	gcc exemplo.o main.c -o main

exemplo.o:	exemplo.h
	gcc -c exemplo.c

clean:
	rm -rf *.o

run:
	./main
	
	
	a@linux:~$ cd /home/a/Desktop/prog2
a@linux:~/Desktop/prog2$ make
cc    -c -o exemplo.o exemplo.c
gcc exemplo.o main.c -o main
/usr/bin/ld: /tmp/ccEBlQjP.o: in function `somar':
main.c:(.text+0x0): multiple definition of `somar'; exemplo.o:exemplo.c:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status
make: *** [makefile:2: all] Error 1
a@linux:~/Desktop/prog2$ 


	
	
	
	


