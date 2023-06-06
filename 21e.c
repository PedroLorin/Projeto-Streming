#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_LETRAS 26

int is_alpha(char c) {
    c = tolower(c);
    return (c >= 'a' && c <= 'z');
}

int main() {
    char nome[51];
    FILE* arquivo;
    int contagem[NUM_LETRAS] = {0};
    char c;

    printf("Digite o nome do arquivo: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    while ((c = fgetc(arquivo)) != EOF) {
        if (is_alpha(c)) {
            c = tolower(c);
            contagem[c - 'a']++;
        }
    }

    for (int i = 0; i < NUM_LETRAS; i++) {
        if (contagem[i] > 0) {
            printf("Letra %c: %d ocorrências\n", 'a' + i, contagem[i]);
        }
    }

    fclose(arquivo);

    return 0;
}