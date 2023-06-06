#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*3) Elabore uma função que receba como parâmetro um valor inteiro n e gere como saída um triângulo lateral formado
 por asteriscos conforme o exemplo a seguir, em que usamos n = 4:
*
**
***
****
***
**
*

*/

void Triangulo(int n)
{

for(int l=0 ; l < n-1 ; l++){
    
    for (int i = -1; i < l; i++)
    {
        printf("*");
     
    }
     printf("\n");
}


for(int l=0 ; l <n ; l++){
    
    for (int i = l; i <n ; i++)
    {
        printf("*");
     
    }
     printf("\n");
     



}


}


int main(){

int n;

printf("digite o numero que deseja fazer o triangulo:  ");
scanf("%d",&n);
Triangulo(n);





return 0 ;
}


