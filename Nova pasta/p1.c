#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*1) Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, seu esporte, idade e altura. 
Agora, escreva um programa que leia os dados de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do mais velho.

2) Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia os dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.
Dica: Procure pelo algoritmo BubbleSort no Google

*/


typedef struct {
char nome[51];
char esporte[51];
int idade;
float altura;
}Ficha;
   
int entrada(Ficha ficha[]){


for (int l =0; l < 5; l++)
{   setbuf(stdin,NULL);
    printf("digite o nome do %dº aluno\n",l+1);
    fgets(ficha[l].nome,50,stdin);
    ficha[l].nome[strcspn(ficha[l].nome,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("digite o esporte que %s pratica\n",ficha[l].nome);
    fgets(ficha[l].esporte,50,stdin);
    ficha[l].esporte[strcspn(ficha[l].esporte,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("digite a idade de %s\n",ficha[l].nome);
    scanf("%d",&ficha[l].idade);

    printf("digite a altura de %s\n",ficha[l].nome);
    scanf("%f",&ficha[l].altura);
    setbuf(stdin,NULL);
}
return 0;
}

int Mais_alto(Ficha ficha[], float compara){

int p=0;
for (int l = 0; l < 5; l++)
{
 
   if (ficha[l].altura>compara)
   {
    compara=ficha[l].altura;
     p=l;
   }
   
}
return printf("%s é o mais alto com %2.f de altura\n",ficha[p].nome, compara);


}



int Ordem(Ficha ficha[]){

for (int l = 0; l < 4; l++) {
        for (int c = l+1; c < 5; c++) {
            if  (ficha[l].idade < ficha[c].idade) {
                
                int idade_comp=ficha[l].idade ;
                ficha[l].idade=ficha[c].idade;
                ficha[c].idade=idade_comp;

                 int altura_trade=ficha[l].altura ;
                ficha[l].altura=ficha[c].altura;
                ficha[c].altura=altura_trade;

                setbuf(stdin,NULL);
                char nome_trade[50];
                strcpy(nome_trade, ficha[l].nome);
                strcpy(ficha[l].nome, ficha[c].nome);
                strcpy(ficha[c].nome, nome_trade);
                setbuf(stdin,NULL);

                setbuf(stdin,NULL);
                char esporte_trade[50];
                strcpy(esporte_trade, ficha[l].esporte);
                strcpy(ficha[l].esporte, ficha[c].esporte);
                strcpy(ficha[c].esporte, esporte_trade);
                setbuf(stdin,NULL);


            }
        }
    }



    


 printf("aqui estao todos alunos em ordem de idade\n");
 for(int l=0; l<5;l++){
printf("nome:%s idade:%d  altura:%f  esporte:%s \n",ficha[l].nome,
                                                    ficha[l].idade,
                                                    ficha[l].altura,
                                                    ficha[l].esporte);

 }
 return printf("o mais velho é %s com %d anos\n",ficha[0].nome,ficha[0].idade);

 
}




int main(){

Ficha ficha[5];

    float compara = 0;

entrada(ficha);
Mais_alto(ficha,compara);
Ordem(ficha);




return 0 ;
}