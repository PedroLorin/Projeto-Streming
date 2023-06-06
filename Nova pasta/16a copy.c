#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char pais[20];
    char cidade[20];
    int servidoresAtivos;
    int servidoresComProblemas;
} Notificacao;

Notificacao* realocarVetor(Notificacao* vetor, int tamanho, int novaCapacidade) {
    Notificacao* novoVetor = (Notificacao*)realloc(vetor, novaCapacidade * sizeof(Notificacao));

    if (novoVetor == NULL) {
        printf("Erro de realocação de memória.\n");
        free(vetor);
        return NULL;
    }

    return novoVetor;
}

void receberNotificacoes(Notificacao** vetor, int* capacidade, int* tamanho) {
    int capacidadeInicial = *capacidade;
    int posicao = *tamanho;

    char pais[20];

    while (1) {
        if (posicao >= *capacidade) {
            *capacidade += 5;
            *vetor = realocarVetor(*vetor, capacidadeInicial, *capacidade);

            if (*vetor == NULL) {
                return;
            }
        }

        printf("Digite o país da notificação (ou \"fim\" para encerrar): ");
        scanf("%s", pais);

        if (strcmp(pais, "fim") == 0) {
            break;
        }

        Notificacao notificacao;

        strncpy(notificacao.pais, pais, sizeof(notificacao.pais) - 1);
        notificacao.pais[sizeof(notificacao.pais) - 1] = '\0';

        printf("Digite a cidade da notificação: ");
        scanf("%s", notificacao.cidade);

        printf("Digite a quantidade de servidores ativos: ");
        scanf("%d", &notificacao.servidoresAtivos);

        printf("Digite a quantidade de servidores com problemas: ");
        scanf("%d", &notificacao.servidoresComProblemas);

        (*vetor)[posicao] = notificacao;
        posicao++;
    }

    *tamanho = posicao;
}

void imprimirNotificacoes(Notificacao* vetor, int tamanho) {
    printf("\nRelatório de Notificações:\n");

    for (int i = 0; i < tamanho; i++) {
        printf("Notificação %d:\n", i + 1);
        printf("País: %s\n", vetor[i].pais);
        printf("Cidade: %s\n", vetor[i].cidade);
        printf("Servidores Ativos: %d\n", vetor[i].servidoresAtivos);
        printf("Servidores com Problemas: %d\n", vetor[i].servidoresComProblemas);
        printf("---------------------------\n");
    }
}

int main() {
    int capacidade = 5;
    int tamanho = 0;
    Notificacao* vetor = (Notificacao*)malloc(capacidade * sizeof(Notificacao));

    if (vetor == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    receberNotificacoes(&vetor, &capacidade, &tamanho);
    imprimirNotificacoes(vetor, tamanho);

    free(vetor);

    return 0;
}