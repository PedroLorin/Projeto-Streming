

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, seu esporte, idade e altura.
// Agora, escreva um programa que leia os dados de cinco atletas e os armazene em um arquivo binário


 typedef struct 
 {
    char nome [51];
    char esporte[51];
    int idade;
    float altura;


 }Dados;


int main(){

char arquivo_nome[51];

 Dados dados[5];
 
 printf("agora digite o nome do arquivo que deseja salvar os dados inseridos\n");
 fgets(arquivo_nome,50,stdin);
 arquivo_nome[strcspn(arquivo_nome,"\n")]='\0';
 setbuf(stdin,NULL);


 FILE *arquivo = fopen(arquivo_nome,"wb");

 for (int l = 0; l < 5; l++)
 {  setbuf(stdin,NULL);
    printf("digite o nome do %dº atleta \n",l+1);
    fgets(dados[l].nome,50,stdin);
    dados[l].nome[strcspn(dados[l].nome,"\n")]='\0';
    setbuf(stdin,NULL);

     printf("digite o esporte praticado por  %s:\n ",dados[l].nome);
     fgets(dados[l].esporte,50,stdin);
     dados[l].esporte[strcspn(dados[l].esporte,"\n")]='\0';
     setbuf(stdin,NULL);

     printf("digite a idade de %s\n",dados[l].nome);
     scanf("%d",&dados[l].idade);

     printf("digite a altura de %s\n",dados[l].nome);
     scanf("%f",&dados[l].altura);



    fwrite(dados[l].nome,sizeof(char),51,arquivo);
    fwrite(dados[l].esporte,sizeof(char),51,arquivo);
    fwrite(&dados[l].idade,sizeof(int),1,arquivo);
    fwrite(&dados[l].altura,sizeof(float),1,arquivo);
 }//for
 //usei um for meio q pra tudo pra facilitar


 fclose(arquivo);
  


 





    return 0;
}//main




