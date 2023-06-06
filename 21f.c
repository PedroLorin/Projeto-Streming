#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Elabore um programa no qual o usuário informe o nome de um arquivo texto e uma palavra, e o programa informe o número de vezes que aquela palavra aparece */

int main() {

    FILE* arquivo;
    char nome[51];
    char palavra[51];
    int contador = 0; // conta letras
    int contador_palavras = 0;
    int d=0;
    char c;
    

    printf("Digite a palavra que deseja contar:\n");
    fgets(palavra, 50, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; palavra[i] != '\0'; i++) {
        if ((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z')) {
            contador++;
        }
    } // conta o número de letras da palavra do usuário

    printf("Digite o nome do arquivo:\n");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1); // 1 significa erro
    }

    while ((c = fgetc(arquivo)) != EOF) {
        
      if(d==contador){
        d=0;
        contador_palavras++;
      }
        if (c == palavra[d]) {
              d++;
             
           
        }else{

          d=0;
        }
    }

    printf("A palavra aparece %d vezes.\n", contador_palavras);

    fclose(arquivo);

    return 0;
}