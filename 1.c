

void exibirMenuSeries() {
    int opcao;

    do {
        printf("====== Menu de Séries ======\n");
        printf("1. Cadastrar série\n");
        printf("2. Listar séries\n");
        printf("3. Pesquisar série\n");
        printf("4. Alterar série\n");
        printf("5. Excluir série\n");
        printf("6. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarSerie();
                break;
            case 2:
                listarSeries();
                break;
            case 3:
                // Implementar a função de pesquisa
                break;
            case 4:
                // Implementar a função de alteração
                break;
            case 5:
                // Implementar a função de exclusão
                break;
            case 6:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 6);
}

int main() {
    // Inicialize as variáveis e faça as configurações necessárias

    exibirMenuSeries();

    // Realize outras operações ou finalize o programa
    return 0;
}
