#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

int tamanho=5;
int contador=0;
int* vetor = (int*)malloc(tamanho* sizeof(int)); 

for (int i = 0; i < tamanho; i++)
{
    printf("digite um numero possitivo para salvar ou negativo para encerrar ");
    scanf("%d",&vetor[i]);
    contador++;

    if(vetor[i]<= 0){
        tamanho=contador+1;

        int* novovetor = (int*)malloc(tamanho* sizeof(int)); 

         for (int l = 0; l < tamanho; l++) {
                novovetor[l] = vetor[l];
            }

            free(vetor);
            vetor=novovetor;
            i=tamanho+1;
    }

    if (tamanho==contador)
    {
        tamanho=tamanho+5;
        int* novovetor = (int*)malloc(tamanho* sizeof(int)); 
        
        
            for (int l = 0; l < tamanho; l++) {
                novovetor[l] = vetor[l];
            }

            free(vetor);
            vetor=novovetor;
        i=0;
    }

}

for (int i = 0; i < tamanho; i++){

printf("%d",vetor[i]);

}

return 0 ;
}


