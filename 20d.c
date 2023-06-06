#include<string.h>
#include<stdlib.h>
#include<stdio.h>


/*Escreva uma função que receba como parâmetro um valor L e um valor C e 
retorne o ponteiro para uma matriz alocada dinamicamente contendo L linhas e C colunas.
 Essa matriz deve ser inicializada com o valor 0 em todas as suas posições.*/


int** geramatriz (int l , int c){

int **matriz = (int **) malloc(l * sizeof(int*));
for (int i = 0; i < l; i++){
 matriz[i] = (int *) malloc(c * sizeof(int));

}// for

for (int i = 0; i < l; i++)
{
  for (int  t = 0; t < c; t++)
  {
    matriz[i][t]=0;  
  }
}


return matriz;
}





int main(){

int l;
int c;
printf("digite a quantia de linhas: ");
scanf("%d",&l);

printf("agora digite a quantia de colunas: ");
scanf("%d",&c);


int** matriz = geramatriz(l,c);

 

for (int i = 0; i < l; i++)
{
  for (int  t = 0; t < c; t++)
  {
   printf("%d ",matriz[i][t]); 
  }
  printf("\n");
}

 
 for (int i = 0; i < l; i++) {
        free(matriz[i]);
    }
free(matriz);




    return 0;

}

