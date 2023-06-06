#include<string.h>
#include<stdlib.h>
#include<stdio.h>
/*Considere a seguinte declaração:
   int a, *b, **c, ***d;
   Escreva um programa que receba o valor de a, calcule e exiba:

O dobro do valor a, utilizando o ponteiro b
O triplo do valor a, utilizando o ponteiro c
O quadruplo do valor a, utilizando o ponteiro d
*/
#include <stdio.h>

int main() {
    int a;
    printf("Digite um valor para a: ");
    scanf("%d", &a);

    int* b = &a;
    int** c = &b;
    int*** d = &c;



    printf("O dobro de %d = %d\n", a, *b*2);
    printf("O triplo de %d = %d\n", a, **c*3);
    printf("O quadruplo de %d = %d\n", a, ***d*4);

    return 0;
}



