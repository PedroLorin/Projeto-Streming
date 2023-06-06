

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//Crie uma estrutura representando um atleta. Essa estrutura deve conter o nome do atleta, seu esporte, idade e altura.
// Agora, escreva um programa que leia os dados de cinco atletas e os armazene em um arquivo binário
//Considerando a estrutura atleta do exercício anterior, escreva um programa que leia um arquivo binário contendo 
//os dados de cinco atletas. Calcule e exiba o nome do atleta mais alto e do mais velho.


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
 float maior = 0;//salva a altura do mais alto
 int velho = 0;//salva a idade do mais velho
 int posicao[2];//0 para idade e 1 para altura assim eu consigo jogar na possição do aluno mais velho e mais alto
 
 printf("digite o nome do arquivo que deseja ler\n");
 fgets(arquivo_nome,50,stdin);
 arquivo_nome[strcspn(arquivo_nome,"\n")]='\0';
 setbuf(stdin,NULL);


 FILE *arquivo = fopen(arquivo_nome,"rb");

 for (int l = 0; l < 5; l++)
 {  


    fread(dados[l].nome,sizeof(char),51,arquivo);
    fread(dados[l].esporte,sizeof(char),51,arquivo);
    fread(&dados[l].idade,sizeof(int),1,arquivo);
    fread(&dados[l].altura,sizeof(float),1,arquivo);
    

    if (dados[l].idade > velho )
    {
     velho = dados[l].idade ;
     posicao[0]=l;//dessa forma eu localizo quem foi o teve o maior valor 
    }//if para acha o mais velhor

    if (dados[l].altura > maior )
    {
     maior = dados[l].altura ;
     posicao[1]=l;//dessa forma eu localizo quem foi o teve o maior valor 
    }//if para encontar o maior

    
 }//for
 //usei um for meio q pra tudo pra facilitar

printf("A maior altura é %2.f, pertecente a %s\n",maior,dados[posicao[1]].nome);

printf("A maior idade é %d, pertecente a %s",velho,dados[posicao[0]].nome);
 fclose(arquivo);
  


 





    return 0;
}//main




