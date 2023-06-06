/*Escreva um programa que receba um número inteiro representando a quantidade total de segundos e,
 usando passagem de parâmetros por referência, converta a quantidade informada de segundos em Horas, Minutos e Segundos.
  Imprima o resultado da conversão no formato HH:MM:SS. Utilize o seguinte protótipo da função:
void converteHora(int total_segundos, int* hora, int* min, int* seg)*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void converteHora(int total_segundos, int* hora, int* min, int* seg) {
  *(hora) = total_segundos / 3600;
  total_segundos %= 3600;//TRANFORMA NO RESULTADO DO RESTO PARA CONTAR OS MINS
  *(min) = total_segundos / 60;//AQUI DA OS MINUTOS NA DIVISÃO O RESTANTE N IMPORTA
  *(seg) = total_segundos % 60;// O RESTANTE SERIA OS SEGUNDOS AQUI
}

int main() {
  int total_segundos, hora, min, seg;

  printf("Digite a quantidade total de segundos: ");
  scanf("%d", &total_segundos);

  converteHora(total_segundos, &hora, &min, &seg);

  printf("Tempo convertido: %02d:%02d:%02d\n", hora, min, seg);

  return 0;
}