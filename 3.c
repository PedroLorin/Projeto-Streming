#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa e:

–Crie e leia 5 eletrodomésticos que contém nome (máximo 15 letras), potência (real, em kW) 
e tempo ativo por dia (real, em horas).

–Leia um tempo t (em dias), calcule e mostre o consumo 
total na casa e o consumo relativo de cada eletrodoméstico
(consumo/consumo total) nesse período de tempo. Apresente este último dado em porcentagem.*/


typedef struct 
{
    char nome[16];
    float potencia;
    float usohoras;//tempo que usou o aparelho 
    float dias;
}Eletro;// recebe os dados basicos de cada aparelho

typedef struct 
{
    Eletro eletro[5];
    int dias;
    float parcialhoras[5];
    float totalpotencia;
    float porcentagem[5];
}Tempo;//meche com os dados em função do tempo


 int main(){

 Tempo tempo;

 for(int l = 0; l< 5; l++)
 {
    setbuf(stdin,NULL);
    printf("digite o nome do %dº eletrodoméstico desejado\n",l+1);
    fgets(tempo.eletro[l].nome,15,stdin);
    tempo.eletro[l].nome[strcspn(tempo.eletro[l].nome,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("Digite a potentecia do eletrodomestico\n"); 
    scanf("%f",&tempo.eletro[l].potencia);
    
    printf("digite as horas de uso diario\n");
    scanf("%f",&tempo.eletro[l].usohoras);

 }//for para registrar os aparelhos e seus dados basicos

setbuf(stdin,NULL);
printf("digite a quantia de dias para os calculos\n");
scanf("%d",&tempo.dias);//entrada para o tempo total dias

for (int l=0; l<5; l++)
{
 tempo.parcialhoras[l]= tempo.dias*tempo.eletro[l].usohoras;//calcula a consumo total do aparelho no periodo de dias inserido
tempo.totalpotencia= tempo.parcialhoras[l]+tempo.totalpotencia;//calcula o consumo total de todos aparelhos
}//for 

printf("o consumo total foi   %0.f kw/hora\n",tempo.totalpotencia);

for (int l=0; l<5; l++)
{
 tempo.porcentagem[l]= 100*tempo.parcialhoras[l]/tempo.totalpotencia;//calcula a porcentagem de cada aparelho
printf("o eletrodoméstico %s gastou %.2f%%\n ",tempo.eletro[l].nome,tempo.porcentagem[l]);//
}//for

 

    return 0;
 }


 