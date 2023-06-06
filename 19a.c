#include<string.h>
#include<stdlib.h>
#include<stdio.h>


/*Escreva um programa que contenha duas variáveis inteiras. Compare os endereços e exiba o endereço e o conteúdo do maior endereço. 
*/

int main(){

int v1 = 1;
int v2=2;



if ( &v2 >&v1 )
{
printf("o maior é o v2 com o endereço: %p   ",&v2);
printf("e o maior valor %d",v2);
}else{

printf("o maior é o v1 com o endereço: %p   ",&v1);
printf("e o maior valor %d",v1);
}



    return 0;
}