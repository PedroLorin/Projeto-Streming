#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*Escreva um programa que leia do usuário os nomes de dois arquivos texto. 
Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos 
(o conteúdo do primeiro seguido do conteúdo do segundo)*/

int main() {
    char nome1[51];
    char nome2[51];
    char nome3[51];
 

    FILE *arquivo1;
    FILE *arquivo2;
    FILE *arquivo3;
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
    printf("Digite o nome do segundo arquivo: ");
    fgets(nome2, 50, stdin);
    nome2[strcspn(nome2, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("Digite o nome do arquivo de saída: ");
    fgets(nome3, 50, stdin);
    nome3[strcspn(nome3, "\n")] = '\0';
    setbuf(stdin, NULL);


    arquivo2 = fopen(nome2, "r");
    if (arquivo2 == NULL) {
        printf("Erro ao abrir o segundo arquivo!\n");
        exit(1);
    }

    arquivo3 = fopen(nome3, "w");
    if (arquivo3 == NULL) {
        printf("Erro ao criar o arquivo de saída!\n");
        exit(1);
    }

    // Copia o conteúdo do primeiro arquivo para o arquivo de saída
    while ((c = fgetc(arquivo1)) != EOF) {
        fputc(c, arquivo3);
    }

    //aqui pensei em por um \n no arquivo para separar a parte 1 e 2 porém fiquei na duvida se era pra continar na frente 
    // mas como o exercicio dizia "conteudo seguido do outro" eu achei melhor deixar assim.
    
      


    // Copia o conteúdo do segundo arquivo para o arquivo de saída
    while ((c = fgetc(arquivo2)) != EOF) {
        fputc(c, arquivo3);
    }

    printf("Arquivo criado com sucesso!\n");

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo3);

    return 0;
}
