

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//considerando a estrutura ranking do exercício anterior, escreva um programa que leia o arquivo gerado contendo os dados dos 5 jogadores

 typedef struct 
 {
    char nome [51];
   
    double pontuacao;//fikei na duvida de como seria a pontuação , ja q tem jogo q é em float por ter 0.5 pontos etc.

 }Rank;


int main(){

char arquivo_nome[51];
 Rank rank[5];

 
 printf("digite o nome do arquivo que deseja salvar os dados\n");
 fgets(arquivo_nome,50,stdin);
 arquivo_nome[strcspn(arquivo_nome,"\n")]='\0';
 setbuf(stdin,NULL);


 FILE *arquivo = fopen(arquivo_nome,"r");
 if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

 for (int l = 0; l < 5; l++)
 {  

   fscanf(arquivo,"%s %lf", &rank[l].nome,&rank[l].pontuacao);
   printf( "%s  %2.lf\n", rank[l].nome,rank[l].pontuacao);

 }//for



 fclose(arquivo);
  


 





    return 0;
}//main




