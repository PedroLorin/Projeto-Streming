

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/*Escreva um programa que leia do usuário o nome de um arquivo texto. Em seguida, mostre na tela quantas linhas esse arquivo possui.

Texto de resposta
*/



int main (){

char nome [51];

FILE* arquivo;
char c;
int linha = 1;

printf("digite o nome do arquivo\n");
fgets(nome,50,stdin);
nome[strcspn(nome,"\n")]='\0';
setbuf(stdin,NULL);



arquivo = fopen(nome, "r");
 if(arquivo== NULL){
    printf("Erro ao abrir o arquivo!\n");
    exit(1);// 1 significa erro
 }// if
 

while ((c = fgetc(arquivo)) != -1)
{
    if (c == '\n')
    {
        linha++;
    }
    
}

printf("existem %d linhas",linha);


 fclose(arquivo);

    return 0;
}