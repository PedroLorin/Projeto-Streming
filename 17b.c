/*Escreva um programa que receba um número inteiro representando a quantidade total de segundos e,
 usando passagem de parâmetros por referência, converta a quantidade informada de segundos em Horas, Minutos e Segundos.
  Imprima o resultado da conversão no formato HH:MM:SS. Utilize o seguinte protótipo da função:
void converteHora(int total_segundos, int* hora, int* min, int* seg)*

FEITO

/

/*Reescreva o exercício anterior utilizando a estrutura horário (contendo hora, minuto e segundo)
 e passando a estrutura por referência. Utilize o seguinte protótipo da função:
void converteHorario(int total_segundos, Horario* hor))*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct 
{
 int horas;
 int minutos;
 int segundos;   
}Horario;

void converteHorario(int total_segundos, Horario* hor)
{
  hor->horas = total_segundos/3600;
  total_segundos %= 3600;
  hor->minutos = total_segundos/60;
  hor->segundos =  total_segundos % 60;
}

int main(){

 int total_segundos;
 Horario hor;

 printf("digite a quantia de segundo que deseja converter: ");
 scanf("%d",&total_segundos);

 converteHorario(total_segundos, &hor);
 
 printf("Tempo convertido: %02d:%02d:%02d\n",hor.horas,
                                             hor.minutos,
                                             hor.segundos);



  return 0;
}


