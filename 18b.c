
/*Crie uma função que retorne x*y através de operação de soma. A função recebe x e y por parâmetro*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int Mult(int n, int n2) {

if(n == 0){ 

 return 0;
 } else { 
 
 return n2 + Mult (n-1,n2);

 }//else
}//exibeNumeros


int main() {
    int n;
    int n2;
printf("digite o numero que multiplicar: ");
scanf("%d",&n2);
printf("digite o outro numero: ");
scanf("%d",&n);
int numero = Mult(n,n2);

printf("%d",numero);
return 0;
}// main

