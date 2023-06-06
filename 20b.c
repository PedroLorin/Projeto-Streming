#include<string.h>
#include<stdlib.h>
#include<stdio.h>


/*Escreva uma função que receba um valor inteiro positivo N por parâmetro
 e retorne o ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou igual a zero, um ponteiro nulo deverá ser retornado.*/


int alocavetor (int n){

int* vetor = malloc(n*sizeof(int));

if(n <= 0){

    return NULL;
}
for (int i = 0; i < n; i++){
 printf("insira o %dº de seu vetor: ",i+1);
 scanf("%d",&vetor[i]);
}// for
printf("\n");

return vetor;
}




int main(){

int n;

printf("digite o valor de N: ");
scanf("%d",&n);


int* vetor = alocavetor(n);
if (vetor == NULL) { // Verifica se o ponteiro retornado é nulo
        printf("Erro: N precisa ser um inteiro positivo maior que zero.\n");
    } else {
for (int i = 0; i < n; i++){
 printf("%d\n",vetor[i]);

printf("\n");
}// for
}
free(vetor);


    return 0;

}

