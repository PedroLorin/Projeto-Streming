/*Crie um Sistema de Gerenciamento de Bandas seguindo os seguintes passos:
a) Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o nome da banda, que tipo de música ela toca, o número de integrantes e em que posição do ranking 
essa banda está dentre as suas 5 bandas favoritas;
b) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.
c) Crie uma função que peça ao usuário um número de 1 até 5. Em seguida, seu programa deve exibir informações da 
banda cuja posição no seu ranking é a que foi solicitada pelo usuário;
-+-
e) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está entre suas bandas favoritas ou não;
f) Agora junte tudo e crie um menu com as opções de preencher as estruturas e todas as opções das questões passadas.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct
{
char nome[51];
char genero[51];
int integrantes;
int rank;
}Bandas;


void Entrada_bandas( Bandas* bandas)
{
    for (int l = 0; l < 5; l++)
{
    printf("digite o nome da %dº banda: ",l+1);
    fgets(bandas[l].nome,50,stdin);
    bandas[l].nome[strcspn(bandas[l].nome,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("digite o genero da banda %s: ",bandas[l].nome);
    fgets(bandas[l].genero,50,stdin);
    bandas[l].genero[strcspn(bandas[l].genero,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("digite o numero de integrantes da banda %s: ",bandas[l].nome);
    scanf("%d",&bandas[l].integrantes);

    printf("digite o ranking da banda %s: ",bandas[l].nome);
    scanf("%d",&bandas[l].rank);
      printf("\n");
    setbuf(stdin,NULL);
}

}

void Exibe_dados(Bandas* bandas)
{

    for (int l = 0; l <5; l++)
    {
     printf("Banda: %s",bandas[l].nome);
     printf("\ngenero musical: %s",bandas[l].genero);
     printf("\nintegrantes: %d",bandas[l].integrantes);
     printf("\nRanking: %d",bandas[l].rank);
      printf("\n");
     printf("\n");
    }
    
}

void Seleciona_bandas(int num, Bandas* bandas){


  if(num < 1 || num > 5){
        printf("num invalida!\n");
        setbuf(stdin,NULL);
    } else {
        printf("\n informações da terceira banda %dª banda: \n", num);
        printf("Banda: %s\n", bandas[num-1].nome);
        printf("Genero: %s\n", bandas[num-1].genero);
        printf("Integrantes: %d\n", bandas[num-1].integrantes);
        printf("Ranking: %d\n", bandas[num-1].rank);
        setbuf(stdin,NULL);
    }
}

void verifica_banda(Bandas* bandas, char* nome_busca) {
    

    for (int l = 0; l < 5; l++) {
        
        if (strcmp(bandas[l].nome, nome_busca) == 0) {
            printf("%s está entre as suas bandas favoritas!\n", nome_busca);
           setbuf(stdin, NULL);
            return;
        }
    }
 
    printf("%s não está entre as suas bandas favoritas.\n", nome_busca);
    setbuf(stdin, NULL);
}


int main(){

Bandas bandas[5];
int num;
char nome_busca[51];
int opcao;



do {
    printf("Escolha uma opcao:\n");
    printf("1 - Inserir bandas e informações\n");
    printf("2 - Exibir dados das bandas\n");
    printf("3 - Selecionar uma banda\n");
    printf("4 - Verificar se uma banda está entre as favoritas\n");
    printf("5 - Sair\n");

    scanf("%d", &opcao);

    switch (opcao) {
        
        case 1:
            setbuf(stdin, NULL);
            Entrada_bandas(bandas);
            break;
        
        case 2:
            setbuf(stdin, NULL);
            Exibe_dados(bandas);
            break;
        
        case 3:
            setbuf(stdin, NULL);
            printf("Digite o numero de 1 a 5 para selecionar a banda: ");
            scanf("%d", &num);
            Seleciona_bandas(num, bandas);
            break;
        
        case 4:
            setbuf(stdin, NULL);
            printf("Digite o nome da banda que deseja verificar se está entre suas favoritas: ");
            fgets(nome_busca, 50, stdin);
            nome_busca[strcspn(nome_busca,"\n")] = '\0';
            verifica_banda(bandas, nome_busca);
            break;
        
        case 5:
            setbuf(stdin, NULL);
            printf("Saindo...\n");
            break;
        
        default:
            setbuf(stdin, NULL);
            printf("Opcao invalida! Tente novamente.\n");
            break;
    }
} while (opcao != 5);


return 0;
}