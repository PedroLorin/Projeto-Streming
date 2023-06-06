#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int Fatorial(int n) {

if(n == 0){ 

 return 1;
 } else { 
 
 return n * Fatorial (n-1);

 }//else
}//exibeNumeros


int main() {
int n;

printf("insira o numero: ");
scanf("%d",&n);
int numero = Fatorial(n);

printf("%d",numero);
return 0;
}// main