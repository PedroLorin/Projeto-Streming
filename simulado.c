#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*Você foi contratado pela Riot Games para elaborar partes do sistema sistema de Ranking do League of Legends. Para isso:

a) Defina um tipo e estrutura para salvar os dados de jogadores para um Ranking.
Cada jogador possui: nome, vitórias, derrotas, tier(nível) e pontos.

Os tiers são: Bronze, Prata, Ouro, Platina, Diamante e Desafiante. Para organizar os níveis utilize uma enumeração.

b) Receba do teclado e armazene os dados de 6 jogadores. Não devem ser permitidos valores negativos, novos valores devem ser solicitados caso necessário.

c) Exiba uma tabela alinhada com o nome e a taxa de vitórias (winrate) de cada jogador
  winrate = vitórias / (vitórias+derrotas) * 100.
  Cada calculo deve ser feito por meio de uma função adicional que recebe o número de vitórias e derrotas via cópia e retorna o winrate.

d) Exiba uma tabela com os líderes (maior número de pontos) de cada um dos níveis. Para isso, faça uma função extra que receba um tier e retorne uma estrutura do tipo Jogador com os dados do líder.

e) Faça a busca de um jogador pelo nome digitado. A busca deve ser feita por uma função adicional que recebe o nome e retorna os dados de vitórias, derrotas, tier e pontos via referência.

f) Utilizando uma função recursiva, calcule a soma de todas as partidas (vitórias e derrotas) de todos os jogadores.

Cada um dos itens de B a E deve ser implementada em uma função diferente.
Não é permitido o uso de variáveis globais.
Nas funções extras, caso necessário, utilize parâmetros adicionais.*/

typedef enum { Bronze=1 , Prata, Gold, Platina, Diamante, Desafiante }elo;

typedef struct{
    char nick[21];
    int win;
    int lost;
    int elo;
    int pdl;

}Conta;//letra A


void Registro(Conta* conta){

    for(int l=0; l<6; l++){

        setbuf(stdin,NULL);
        printf("insira  o nick do player Nº%d:\n",l+1);
        fgets(conta[l].nick,20,stdin);
        conta[l].nick[strcspn(conta[l].nick,"\n")] ='\0';

        printf("insire a quantidade de vitórias de %s:  ",conta[l].nick);
        scanf("%d",&conta[l].win);
        while (conta[l].win<0 )
        {
            printf("insira um numero possitivo! caso tenha apenas derrotas digite 0\n");
            scanf("%d",&conta[l].win);
        }//while

        printf("insire a quantidade de derrotas de %s:  ",conta[l].nick);
        scanf("%d",&conta[l].lost);
        while (conta[l].lost<0 )
        {
            printf("insira um numero possitivo! caso tenha apenas vitórias digite 0\n");
            scanf("%d",&conta[l].lost);
        }//while

        printf("insire a quantidade de PLDs de %s:  ",conta[l].nick);
        scanf("%d",&conta[l].pdl);
        while (conta[l].pdl<0 )
        {
            printf("insira um numero possitivo! \n");
            scanf("%d",&conta[l].pdl);
        }//while

        printf("digite o numero equivalente ao elo de %s , sendo bronze = 1, prata = 2, gold = 3 platina=4, diamante = 5 e desafiante = 6\n ",conta[l].nick);
        scanf("%d",&conta[l].elo);
        while (conta[l].elo<0 || conta[l].elo > 6 )
        {
            printf("insira um elo válido! \n");
            scanf("%d",&conta[l].elo);
        }//while
   
    }//for
}//função void    //letra B







//começo da c
float Soma(int win, int lost) {
    float soma = 0;

    for (int l = 0; l < 6; l++) {
        soma = win + lost;
    }


    return soma;
}

float Divicao(int win, int lost) {
    float soma = Soma(win, lost);
    if (soma == 0)
{
    return 0 ;
}
    float divicao = win / soma;
    return divicao;
}

float resultado(int win, int lost) {
    float divicao = Divicao(win, lost);
    return 100 * divicao;
}

//inicio da D

void tabela(Conta* conta) {
    printf("%-21s %-8s\n", "Nome", "Winrate");
    for (int l = 0; l < 6; l++) {
        printf("%-21s %-8.2f\n", conta[l].nick, resultado(conta[l].win, conta[l].lost));
    }
}// final da c 


void BuscaConta(Conta* conta) {
    char nomeBuscado[21];
    int encontrado = 0;

        setbuf(stdin,NULL);
    printf("Insira o nome do jogador que deseja buscar: ");
    fgets(nomeBuscado, 20, stdin);
    nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';

    for(int l=0; l<6; l++) {
        if(strcmp(conta[l].nick, nomeBuscado) == 0) {
         
            printf("\nDados da conta de %s:\n", conta[l].nick);

            printf("Wins: %d\n", conta[l].win);
            printf("Losses: %d\n", conta[l].lost);
            printf("PLDs: %d\n", conta[l].pdl);
            printf("Elo: %d\n", conta[l].elo);
            encontrado = 1;
            break;
        }
    }

    if(!encontrado) {
        printf("O jogador com o nome %s não foi encontrado.\n", nomeBuscado);
    }
}
//final da D

int main(){
   

    Conta conta[6];

    Registro(conta);
     
    tabela(conta);




return 0 ;
}


