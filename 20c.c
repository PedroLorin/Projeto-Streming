#include<string.h>
#include<stdlib.h>
#include<stdio.h>


/*Escreva uma função que receba como parâmetro dois vetores via referência( A e B) e o tamanho N.
 A função deve retornar o ponteiro para um vetor C de tamanho N alocado dinamicamente, em que:
C[i] = A[i] * B[i]*/


int* alocavetor (int n){

int* vetor = malloc(n*sizeof(int));

for (int i = 0; i < n; i++){
 printf("insira o %dº de seu vetor: ",i+1);
 scanf("%d",&vetor[i]);
}// for

return vetor;
}


int* vetorproduto(int n , int* vetorA , int* vetorB){


int* vetor = malloc(n*sizeof(int));

for (int i = 0; i < n; i++){
vetor[i]=vetorA[i]*vetorB[i];
}// for


return vetor;
}




int main(){

int n;
printf("digite o valor de N: ");
scanf("%d",&n);


int* vetorA = alocavetor(n);
int* vetorB = alocavetor(n);

int* vetorC = vetorproduto(n,vetorA,vetorB);
 printf("Vetor C: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetorC[i]);
    }
    printf("\n");


free(vetorA);
free(vetorB);
free(vetorC);



    return 0;

}

