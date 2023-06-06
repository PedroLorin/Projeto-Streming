#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*1) Crie uma enumeração representando os meses do ano.
Agora, escreva um programa que leia um valor inteiro do
teclado e exiba o nome do mês correspondente e a
quantidade de dias que ele possui. */
typedef enum {JANEIRO=1,FEVEREIRO,MARCO,ABRIL,MAIO,JUNHO,JULHO,AGOSTO,SETEMBRO,OUTUBRO, NOVEMBRO,DEZEMBRO}Mes;

int main(){

int numero;

 printf("digite o numero que represeta o mês desejado\n");
 scanf("%d",&numero);
  switch(numero){
    case JANEIRO: printf(" Janeiro tem 31 dias\n");  break;

    case FEVEREIRO: printf(" FEVEREIRO tem 28 dias\n");  break;

    case MARCO: printf(" MARÇO tem 31 dias\n");  break;

    case MAIO: printf(" MAIO tem 31 dias\n");  break;

    case ABRIL: printf(" ABRIL tem 30 dias\n");  break;

    case JUNHO: printf(" JUNHOtem 30 dias\n");  break;

    case JULHO: printf(" JULHO tem 31 dias\n");  break;

    case AGOSTO: printf(" AGOSTO tem 31 dias\n");  break;

    case SETEMBRO: printf(" SETEMBRO tem 30 dias\n");  break;

    case OUTUBRO: printf(" OUTUBRO tem 31 dias\n");  break;
 
    case NOVEMBRO: printf(" NOVEMBRO tem 30 dias\n");  break;

    case DEZEMBRO: printf(" DEZEMBRO tem 31 dias\n");  break;
    default:
   printf("Número de mês inválido\n"); break;
 }//switch1


    return 0;
}


