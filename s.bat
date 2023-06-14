int main() {
    int indiceHistorico = 0;
    int QuantidadeSeries = 258;
    Serie *serie = (Serie*) malloc(QuantidadeSeries * sizeof(Serie));


    Historico *historico =(Historico*)malloc(indiceHistorico * sizeof(Historico)); 

    FILE *arquivo = fopen("streaming_db.dat", "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo Binario , tentaremos excutar o arquivo csv.\n");
        
        FILE *arquivo = fopen("streaming_db.txt", "r");

         if (arquivo == NULL) {
             perror("Erro ao abrir o arquivo CSV.\n");
              return 1;
        }
        lerSeries(serie, QuantidadeSeries, arquivo);
        
    }else{

        lerSeriesBinario(serie, QuantidadeSeries, arquivo);
        salvaDados(serie,QuantidadeSeries);

    }

    imprimirSeries(serie, QuantidadeSeries);
    //QuantidadeSeries = cadastrar(QuantidadeSeries, serie);
    //apagar(QuantidadeSeries, serie);
    BuscaGenero(serie,QuantidadeSeries);
   // Alterar(QuantidadeSeries, serie);
   // Pesquisa(serie,QuantidadeSeries);
    indiceHistorico=salvaHistorico(serie,QuantidadeSeries,historico,indiceHistorico);
    salvaDados(serie,QuantidadeSeries);





    free(serie);
    free (historico);
    fclose(arquivo);
    

    return 0;
}
