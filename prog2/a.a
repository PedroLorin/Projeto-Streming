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

all: exemplo.o
	gcc exemplo.o main.c -o main

exemplo.o:	exemplo.h
	gcc -c exemplo.c

clean:
	rm -rf *.o

run:
	./main


