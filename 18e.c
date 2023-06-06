#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Conversor(int decimal) {
  if (decimal == 0) {
    return;
  }
  decimalParaBinario(decimal / 2);
  printf("%d", decimal % 2);
}

int main() {
  int decimal;
  printf("Digite um número decimal: ");
  scanf("%d", &decimal);
  printf("O número %d em binário é: ", decimal);
  Conversor(decimal);
  printf("\n");
  return 0;
}