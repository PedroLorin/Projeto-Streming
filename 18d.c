/*Faça uma função recursiva que retorne o n-ésimo termo da sequência de Fibonacci, sendo que n é recebido por parâmetro.
 Utilize essa função para desenvolver um programa que mostre no main() os n termos dessa sequência na tela,
 a partir do valor de n recebido pelo teclado. Sabe-se que o 1º termo é 0 e o 2º termo é 1.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void fibonacci(int n, int n1, int n2) {
  if (n == 0) {
    return;
  }
  printf("%d ", n1);
  fibonacci(n-1, n2, n1+n2);
}

int main() {
  int n;
  printf("Digite um número inteiro positivo: ");
  scanf("%d", &n);
  
  
  fibonacci(n, 0, 1);
  return 0;
}