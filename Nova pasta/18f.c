

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int X(int n,int n2){
  if(n <=0){

  return 0;
  } 
  else{
   
int n3 =n;
 for (int l = 0; l < n3; l++)
 {
    n2= n + n2 ;
    n=n-1;
 }
 return n2;
  }
}//X

int main() {
int n;
int n2;
int resultado;

printf("insira o numero: ");
scanf("%d",&n);

resultado= X(n,0);
printf("%d",resultado);
 return 0;
}// main