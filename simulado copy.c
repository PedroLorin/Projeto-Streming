#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*Na tarde de ontem, 06 de dezembro, alguns servidores da Amazon (AWS) pararam de funcionar. Com isso, diversos serviços ficaram indisponíveis. Dentre eles, os servidores da Riot responsáveis pelos jogos League of Legends, Valorant e Wild Rift.
Você foi convocado em uma missão de emergência para ajudar a identificar os locais das falhas e gerar os relatórios para os técnicos responsáveis por reestabelecer os serviços.

Para isso, a central da Amazon está recebendo as notificações de falhas ao redor do mundo. Você devera implementar um sistema para salvar e processar essas notificações. Para isso:


b) (10 pontos) Receba os dados de diversas notificações de falhas e vá armazenando neste vetor de Notificações.
 A cada vez que o tamanho do vetor se tornar insuficiente, realoque seu tamanho aumentando o vetor em 5 unidades.
Ao receber o valor "fim" como entrada de um pais, o sistema de entradas deverá parar e o vetor tamanho do vetor ajustado ao tamanho exato da quantidade de relatórios.

c) (5 pontos) Salve os dados em um aquivo BINÁRIO chamado "notifications.dat". Feche o arquivo e libere a memória utilizada pelo vetor;

d) (5 pontos) Abra o arquivo gerado anteriormente, carregue os dados em um vetor de Relatórios alocado dinamicamente.



Os países possíveis são: Brasil, EUA, França, Londres, China e Japão*/

typedef struct{
    char pais[20];
    char cidade[20];
    int server_ativo;
    int server_caido;
    

}Notificacao;//letra A


void leArquivo(Notificacao* relatorio ,int capacidade) {
    FILE *arquivo = fopen("notifications.dat", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < capacidade; i++)
    {
        fread(relatorio[i].pais,sizeof(char),20,arquivo);// Lê 20 caracteres
        fread(relatorio[i].cidade,sizeof(char),20,arquivo);// Lê 20 caracteres
       fread(&relatorio[i].server_ativo,sizeof(int),1,arquivo);// Lê um número real
        fread(&relatorio[i].server_caido,sizeof(int),1,arquivo);// Lê um número real
    }
 


    fclose(arquivo);
}


void gerarArquivo(Notificacao* notificacao, int capacidade) {
    FILE *arquivo = fopen("notifications.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    for (int i = 0; i < capacidade; i++)
    {
        fwrite(notificacao[i].pais,sizeof(char),20,arquivo);// Lê 20 caracteres
        fwrite(notificacao[i].cidade,sizeof(char),20,arquivo);// Lê 20 caracteres
        fwrite(&notificacao[i].server_ativo,sizeof(int),1,arquivo);// Lê um número real
        fwrite(&notificacao[i].server_caido,sizeof(int),1,arquivo);// Lê um número real
    }
 

    free(notificacao);
    fclose(arquivo);
}



void aumenta_vetor(Notificacao* notificacao, int* capacidade,int *contador){

    *capacidade +=5;


    Notificacao* novo_notificacao = (Notificacao*)realloc(notificacao, (*capacidade) * sizeof(Notificacao));
    if (novo_notificacao == NULL) {
            printf("Erro de realocação de memória.\n");
            return;
            }//if
    notificacao=novo_notificacao;

    recebe_dados(notificacao,&contador, &capacidade);
}//aumenta valou função

void recebe_dados (Notificacao* notificacao,int* contador, int* capacidade)
{

 for (int i = *contador; i <*capacidade; i++) 
 {



    setbuf(stdin,NULL);
    printf("digite o nome do pais ou digite fim para encerrar:\n");
    fgets(notificacao[i].pais, sizeof(notificacao[i].pais), stdin);
    notificacao[i].pais[strcspn(notificacao[i].pais,"\n")]='\0';
    setbuf(stdin,NULL);
  

 if (strcmp(notificacao[i].pais, "fim") == 0) {
    *capacidade = i;

    Notificacao* novo_notificacao = (Notificacao*)realloc(notificacao, (*capacidade) * sizeof(Notificacao));
        if (novo_notificacao == NULL) {
                printf("Erro de realocação de memória.\n");
                return;
                }//if
        notificacao=novo_notificacao;
    i= *capacidade+1;
}//if

if (strcmp(notificacao[i].pais, "Brasil") == 0 || strcmp(notificacao[i].pais, "EUA") == 0 || strcmp(notificacao[i].pais, "Londres") == 0 || strcmp(notificacao[i].pais, "China") == 0 || strcmp(notificacao[i].pais, "japao") == 0) 
{

    printf("digite o nome da cidade:\n");
    fgets(notificacao[i].cidade, sizeof(notificacao[i].cidade), stdin);
    notificacao[i].cidade[strcspn(notificacao[i].cidade,"\n")]='\0';
    setbuf(stdin,NULL);

    printf("digite a quantidade de servidores ativos:\n");
    scanf("%d",&notificacao[i].server_ativo);

    
    printf("digite a quantidade de servidores caidos:\n");
    scanf("%d",&notificacao[i].server_caido);
    
    (*contador)++;


    if (*contador== *capacidade)
    {
        aumenta_vetor(notificacao,capacidade,contador);
    }//if
   
}else{

    i--;
}//corige se for inserido um pais invalido , ja q sera reescrito por cima um valido.




 }//for

}//função void



int main(){
    int contador=0;
    int capacidade = 5;
    
    
    Notificacao* notificacao = (Notificacao*)malloc(capacidade * sizeof(Notificacao));

    Notificacao* relatorios =(Notificacao*)malloc(capacidade* sizeof(Notificacao));

    if (notificacao == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    recebe_dados(notificacao,&contador, &capacidade);
 
    gerarArquivo(notificacao,capacidade);
    leArquivo(notificacao, capacidade);


return 0 ;
}


