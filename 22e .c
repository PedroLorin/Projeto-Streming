

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//Crie uma estrutura representando um ranking. Essa estrutura deve conter o nome do jogador e sua pontuação. 
//Em seguida, escreva um programa que leia os dados de 5 jogadores e os armazene em um arquivo utilizando a técnica de Dados formatados.


 typedef struct 
 {
    char nome [51];
   
    float pontuacao;//fikei na duvida de como seria a pontuação , ja q tem jogo q é em float por ter 0.5 pontos etc.

 }Rank;


int main(){

char arquivo_nome[51];
 Rank rank[5];

 
 printf("digite o nome do arquivo que deseja salvar os dados\n");
 fgets(arquivo_nome,50,stdin);
 arquivo_nome[strcspn(arquivo_nome,"\n")]='\0';
 setbuf(stdin,NULL);


 FILE *arquivo = fopen(arquivo_nome,"w");

 for (int l = 0; l < 5; l++)
 {  
   setbuf(stdin,NULL);
   printf("o nome do %dº player\n",l+1);
   fgets(rank[l].nome,50,stdin);
   rank[l].nome[strcspn(rank[l].nome,"\n")]='\0';
   setbuf(stdin,NULL); 

printf("digite a pontução do do player: %s \n",rank[l].nome);
   scanf("%f",&rank[l].pontuacao);


   fprintf(arquivo," %s ", rank[l].nome);
   fprintf(arquivo,"%2.f", rank[l].pontuacao);


    
 }//for
 //usei um for meio q pra tudo pra facilitar


 fclose(arquivo);
  


 





    return 0;
}//main




