#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {

    int id;
    char Nome[101];
    char Genero[41];
    int Classificacao;
    char Plataforma[41];
    int QuantidadeTemporadas;
    int QuantidadeEpisodiosTotais;
    int *QuantidadeEpisodiosPorTemporada;
    int DuracaoMediaEpisodios;

} Serie;

void lerSeries(Serie *serie, int QuantidadeSeries, FILE *arquivo) {

    for (int i = 0; i < QuantidadeSeries; i++) 
    {
        serie[i].QuantidadeEpisodiosTotais = 0;

        fscanf(arquivo, "%d,", &serie[i].id);
        fscanf(arquivo, "%[^,\n],", serie[i].Nome);
        fscanf(arquivo, "%[^,\n],", serie[i].Genero);
        fscanf(arquivo, "%d,", &serie[i].Classificacao);
        fscanf(arquivo, "%[^,\n],", serie[i].Plataforma);
        fscanf(arquivo, "%d,", &serie[i].DuracaoMediaEpisodios);
        fscanf(arquivo, "%d,", &serie[i].QuantidadeTemporadas);

        int realoca = serie[i].QuantidadeTemporadas;
        serie[i].QuantidadeEpisodiosPorTemporada = (int*) malloc(realoca * sizeof(int));

        for (int j = 0; j < serie[i].QuantidadeTemporadas; j++) {

            fscanf(arquivo, "%d,", &serie[i].QuantidadeEpisodiosPorTemporada[j]);
      
            serie[i].QuantidadeEpisodiosTotais=serie[i].QuantidadeEpisodiosTotais+serie[i].QuantidadeEpisodiosPorTemporada[j];
        }
    }
}

void imprimirSeries(Serie *serie, int QuantidadeSeries)
{
    printf("Aqui estao todas series cadastradas\n");
    for (int i = 0; i < QuantidadeSeries; i++) 
    {
        printf("%d-", serie[i].id);
        printf("%-40s " , serie[i].Nome);
        printf("Genero:%-20s ", serie[i].Genero);
        printf("Classificacao:%-5d ", serie[i].Classificacao);
        printf("Plataforma:%-15s ", serie[i].Plataforma);
        printf("Duracao media por ep:%-5d ", serie[i].DuracaoMediaEpisodios);
        printf("Quantidade de temporadas:%-5d ", serie[i].QuantidadeTemporadas);
       
        printf("episodios por temporada: ");
        for (int j = 0; j < serie[i].QuantidadeTemporadas; j++) 
        {
            printf("%d ", serie[i].QuantidadeEpisodiosPorTemporada[j]);
        }   

        printf("    Episodios totais: %-5d ",serie[i].QuantidadeEpisodiosTotais);
        printf("\n \n \n");
    }
}


int cadastrar(int QuantidadeSeries , Serie *serie)
{
    QuantidadeSeries++;
  
    serie = (Serie*) realloc(serie, QuantidadeSeries * sizeof(Serie));
    serie[QuantidadeSeries - 1].id= QuantidadeSeries;
    setbuf(stdin,NULL);
 
    printf("digite o nome da serie\n:");
    fgets(serie[QuantidadeSeries - 1].Nome, 101, stdin);
    serie[QuantidadeSeries - 1].Nome[strcspn(serie[QuantidadeSeries-1].Nome, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < QuantidadeSeries - 1; i++)
    {
      
        if (strcasecmp(serie[i].Nome, serie[QuantidadeSeries - 1].Nome) == 0)
        {

            printf("Essa série já está cadastrada. Por favor, insira outro nome.\n");
            QuantidadeSeries--;  // Diminuir o tamanho para cancelar o cadastro da série repetida
          
        }
    }
    
    
    
    serie[QuantidadeSeries-1].QuantidadeEpisodiosTotais= 0;
    printf("digite o genero\n:");
    fgets(serie[QuantidadeSeries - 1].Genero, 12, stdin);
    serie[QuantidadeSeries - 1].Genero[strcspn(serie[QuantidadeSeries-1].Genero, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("digite a classificacao\n");
    scanf("%d", &serie[QuantidadeSeries - 1].Classificacao);
    
    setbuf(stdin, NULL);
    printf("digite plataforma\n");
    fgets(serie[QuantidadeSeries-1].Plataforma, 12, stdin);
    serie[QuantidadeSeries-1].Plataforma[strcspn(serie[QuantidadeSeries-1].Plataforma, "\n")] = '\0';
    setbuf(stdin, NULL);

    printf("diga a dura;'ao media\n:");
    scanf("%d", &serie[QuantidadeSeries - 1].DuracaoMediaEpisodios);
    
    printf("digite a quantia de temporadas\n:");
    scanf("%d", &serie[QuantidadeSeries - 1].QuantidadeTemporadas);


    int realoca = serie[QuantidadeSeries - 1].QuantidadeTemporadas;
    serie[QuantidadeSeries-1].QuantidadeEpisodiosPorTemporada = malloc(realoca * sizeof(int));
    
    for (int i = 0; i < serie[QuantidadeSeries-1].QuantidadeTemporadas; i++)
    { 

        printf("digite a quantia de episodios da %d temporada:",i+1);
        scanf("%d", &serie[QuantidadeSeries-1].QuantidadeEpisodiosPorTemporada[i]);
         serie[QuantidadeSeries-1].QuantidadeEpisodiosTotais=serie[QuantidadeSeries-1].QuantidadeEpisodiosTotais+serie[QuantidadeSeries-1].QuantidadeEpisodiosPorTemporada[i];

    }  

    return QuantidadeSeries;

}




void Alterar(int QuantidadeSeries, Serie *serie)
{
    char alterar[101];
    int encontrar=0;
    int contador=-1;
    char placeHolder[45];
    int realoca=0;
    
    setbuf(stdin, NULL);
    printf("Digite o nome da série que deseja realizar modificacoes no dados meu truta: ");
    fgets( alterar, sizeof( alterar), stdin);
    alterar[strcspn( alterar, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < QuantidadeSeries ; i++)
    {
        contador++;
        if (strcasecmp( alterar, serie[i].Nome) != 0)
        { 
            encontrar =1;
        }else
        {
            encontrar =0;
            break;


        }//else

    }//for
        if(encontrar == 1)
        {
            printf("serie n encontrada, tente outro nome\n");
            
            Alterar(QuantidadeSeries,serie);
        }else
        {
            int caso=0;

            printf("digite 1 para mudar o nome da serie\n");
            printf("digite 2 para mudar o genero da serie\n");
            printf("digite 3 para mudar a clasificacao da serie\n");
            printf("digite 4 para mudar plataforma da serie\n");
            printf("digite 5 para mudar duracao por episodio  da serie\n");
            printf("digite 6 para mudar quantia de temporadas da serie\n");
            scanf("%d",&caso);

                switch (caso) {
            case 1:

                printf(" vc escolheu mudar o nome da serie ");

            
                setbuf(stdin, NULL);
                printf("Digite o nome da série que deseja realizar modificacoes no dados meu truta: ");
                fgets( placeHolder, sizeof(placeHolder), stdin);
                placeHolder[strcspn( placeHolder, "\n")] = '\0';
                setbuf(stdin, NULL);

                strcpy(serie[contador].Nome,placeHolder);


            break;
            case 2:
                    
                    printf("Você escolheu mudar o genero da serie \n");
                    setbuf(stdin, NULL);      
                    
                    printf("Digite os novos generos no modelo genero1/genero2... :\n"); 
                    
                    fgets( placeHolder, sizeof(placeHolder), stdin);
                    placeHolder[strcspn( placeHolder, "\n")] = '\0';
                    setbuf(stdin, NULL);
                    
                    strcpy(serie[contador].Genero,placeHolder);
                      
                    
            break;

            case 3:
                    printf("Você escolheu mudar a classificacao da serie.\n");
                    
                    printf("Digite a nova classificacao da serie:");

                    scanf("%d",&serie[contador].Classificacao);

            break;

            case 4:
                    
                    printf("Voce escolheu mudar a plataforma de streaming da serie.\n");

                    printf("Digite as novas plataformas de streaming\n");


                    strcpy(serie[contador].Plataforma,placeHolder);

              
                    break;  
            
            case 5:
                    printf("Você escolheu mudar a duracao media dos episodios da serie.\n");
                
                    printf("digite a nova duracao media:");

                    scanf("%d",&serie[contador].DuracaoMediaEpisodios);



            break; 
            case 6:
                printf("Você escolheu mudar a quantia de temporadas da serie.\n");
                    
                printf("digite a quantia de temporadas:");

                scanf("%d",&serie[contador].QuantidadeTemporadas);


                printf("digite a nova distribuicao de episodios por temporada");

                realoca = serie[contador].QuantidadeTemporadas;
                serie[contador].QuantidadeEpisodiosPorTemporada = realloc(serie[contador].QuantidadeEpisodiosPorTemporada, realoca * sizeof(int));
                 serie[contador].QuantidadeEpisodiosTotais =  0;
                for (int i = 0; i < realoca; i++)
                { 

                    printf("digite a quantia de episodios da %d temporada:",i+1);
                    scanf("%d", &serie[contador].QuantidadeEpisodiosPorTemporada[i]);
                    serie[contador].QuantidadeEpisodiosTotais=serie[contador].QuantidadeEpisodiosTotais+serie[contador].QuantidadeEpisodiosPorTemporada[i];

                    
                } 

            case 7:
                printf("Você escolheu mudar a quantia de episodios das temporadas\n");
                    
               


                printf("digite a nova distribuicao de episodios por temporada");

                for (int i = 0; i < serie[contador].QuantidadeTemporadas; i++)
                { 

                    printf("digite a quantia de episodios da %d temporada:",i+1);
                    scanf("%d", &serie[contador].QuantidadeEpisodiosPorTemporada[i]);
                    serie[contador].QuantidadeEpisodiosTotais=serie[contador].QuantidadeEpisodiosTotais+serie[contador].QuantidadeEpisodiosPorTemporada[i];

                    
                } 
                            


            break; 





                default:
                    printf("Número inválido.\n");
                    
                Alterar(QuantidadeSeries, serie);

            }

            
          
        }//else
}// void alterar



void apagar(int QuantidadeSeries, Serie *serie)
{
    char deletar[101];
    int encontrar=0;
    int contador=-1;
    
    setbuf(stdin, NULL);
    printf("Digite o nome da série que deseja apagar: ");
    fgets(deletar, sizeof(deletar), stdin);
    deletar[strcspn(deletar, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < QuantidadeSeries ; i++)
    {
        contador++;
        if (strcasecmp(deletar, serie[i].Nome) != 0)
        { 
            encontrar =1;
        }else
        {
            encontrar =0;
            break;


        }//else

    }//for
        if(encontrar == 1)
        {
            printf("serie n encontrada, tente outro nome\n");
            
            apagar(QuantidadeSeries,serie);
        }else
        {

            serie[contador].id=contador+1;
            strcpy(serie[contador].Nome,serie[QuantidadeSeries - 1].Nome);
            strcpy(serie[contador].Genero, serie[QuantidadeSeries - 1].Genero);
            serie[contador].Classificacao=serie[QuantidadeSeries-1].Classificacao;
            strcpy(serie[contador].Plataforma, serie[QuantidadeSeries - 1].Plataforma);
            serie[contador].DuracaoMediaEpisodios=serie[QuantidadeSeries -1].DuracaoMediaEpisodios;
            serie[contador].QuantidadeTemporadas=serie[QuantidadeSeries-1].QuantidadeTemporadas;
            serie[contador].QuantidadeEpisodiosTotais=serie[QuantidadeSeries-1].QuantidadeEpisodiosTotais;

            int realoca = serie[contador].QuantidadeTemporadas;
           serie[contador].QuantidadeEpisodiosPorTemporada = realloc(serie[contador].QuantidadeEpisodiosPorTemporada ,realoca * sizeof(int));
            
            for(int i = 0; i <realoca; i++)
            {
                serie[contador].QuantidadeEpisodiosPorTemporada[i]=serie[QuantidadeSeries-1].QuantidadeEpisodiosPorTemporada[i];
            }//for

            
            

            QuantidadeSeries--;
            
            serie = (Serie *)realloc(serie, QuantidadeSeries * sizeof(Serie));
            imprimirSeries(serie, QuantidadeSeries);

          
        }//else
}// void apagar 



void BuscaGenero(Serie *serie, int QuantidadeSeries)
{ 
    int ContadorGenero = 0;
    char GeneroBusca[41];
    char GeneroCopia[41];
    printf("Digite o Genero que deseja buscar:\n");

    setbuf(stdin, NULL);
    fgets(GeneroBusca, sizeof(GeneroBusca), stdin);
    GeneroBusca[strcspn(GeneroBusca, "\n")] = '\0';
    setbuf(stdin, NULL);

    for (int i = 0; i < QuantidadeSeries; i++)
    {   
        strcpy(GeneroCopia, serie[i].Genero);
        char *GeneroToken = strtok(GeneroCopia, "/");

        while (GeneroToken != NULL)
        {
            if (strcasecmp(GeneroBusca, GeneroToken) == 0)
            {
                ContadorGenero++;
                printf("%d-", serie[i].id);
                printf("%-40s " , serie[i].Nome);
                printf("Genero:%-20s ", serie[i].Genero);
                printf("Classificacao:%-5d ", serie[i].Classificacao);
                printf("Plataforma:%-15s ", serie[i].Plataforma);
                printf("Duracao media por ep:%-5d ", serie[i].DuracaoMediaEpisodios);
                printf("Quantidade de temporadas:%-5d ", serie[i].QuantidadeTemporadas);
            
                printf("episodios por temporada: ");
                for (int j = 0; j < serie[i].QuantidadeTemporadas; j++) 
                {
                    printf("%d ", serie[i].QuantidadeEpisodiosPorTemporada[j]);
                }
                printf("\n");
            
                printf("\n");
            
                printf("\n");
            }
            GeneroToken = strtok(NULL, "/");
        }
    }

    if (ContadorGenero == 0)
    {
        printf("Não há séries desse gênero, tente novamente.\n");
        BuscaGenero(serie, QuantidadeSeries);
    }
}
            
            


        

int main() {
    
    int QuantidadeSeries = 258;
    Serie *serie = (Serie*) malloc(QuantidadeSeries * sizeof(Serie));

    FILE *arquivo = fopen("streaming_db.txt", "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo.\n");
        return 1;
    }

    lerSeries(serie, QuantidadeSeries, arquivo);
    imprimirSeries(serie, QuantidadeSeries);
    QuantidadeSeries = cadastrar(QuantidadeSeries, serie);
    apagar(QuantidadeSeries, serie);
    BuscaGenero(serie,QuantidadeSeries);
    Alterar(QuantidadeSeries, serie);
 



    free(serie);
    fclose(arquivo);

    return 0;
}
