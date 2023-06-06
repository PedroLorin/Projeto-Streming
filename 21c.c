


#include<string.h>
#include<stdlib.h>
#include<stdio.h>


 /*Escreva um programa para converter o conteúdo de um arquivo texto em caracteres maiúsculos.
 O programa deverá ler do usuário o nome do arquivo a ser convertido e o nome do arquivo a ser salvo.
 */



int main (){

char nome1 [51];
char nome2 [51];


FILE* arquivo1;
FILE* arquivo2;
char c;


printf("Digite o nome do primeiro arquivo: ");
    fgets(nome1, 50, stdin);
    nome1[strcspn(nome1, "\n")] = '\0';
    setbuf(stdin, NULL);

    arquivo1 = fopen(nome1, "r");
    if (arquivo1 == NULL) {
        printf("Erro ao abrir o primeiro arquivo!\n");
        exit(1);
    }

printf("Digite o nome do arquivo final que recebera a conversão:");
    fgets(nome2,50,stdin);
    nome2[strcspn(nome2,"\n")]='\0';
    setbuf(stdin,NULL);

    arquivo2=fopen(nome2, "w");
    if(arquivo2 ==NULL){
        printf("Erro ao abrir o primeiro arquivo!\n");
        exit(1);
    }


    while ((c = fgetc(arquivo1)) != EOF) {
        fputc(toupper(c), arquivo2);
    }


 printf("Arquivo criado com sucesso!\n");

    fclose(arquivo1);
    fclose(arquivo2);




    return 0;
}