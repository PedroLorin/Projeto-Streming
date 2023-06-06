#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*2) Escreva um trecho de código para fazer a criação dos
novos tipos de dados conforme solicitado abaixo:
 Horário: composto de hora, minutos e segundos.
 Data: composto de dia, mês e ano.
 Compromisso: local, horário e texto que descreve o
compromisso.*/

 typedef struct{
   int hora;
   int minuto;
   int segundo;
}Horario;
typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    char local[21];
    Horario horario;
    char descricao[51];
   Data data;
}Compromisso;


int main() {
int l=0;
Compromisso evento1;//equivalente a compromisso , troca feita para facilitar na hora de por o codigo


   
printf("digite as horas:\n");
scanf("%i",&evento1.horario.hora);
printf("digite os minutos: \n");
scanf("%i",&evento1.horario.minuto);
printf("digite aos segundos:\n");
scanf("%i",&evento1.horario.segundo);


 for (l = 0; l <1; l++)  
 {
    
    if (evento1.horario.hora >= 24 || evento1.horario.minuto >= 60 ||evento1.horario.segundo >60 ) 
        {
        printf("entrada errada tente novamente");
        printf("digite as horas:\n");
        scanf("%d",&evento1.horario.hora);
        printf("digite os minutos: \n");
        scanf("%d",&evento1.horario.minuto);
        printf("digite aos segundos:\n");
        scanf("%d",&evento1.horario.segundo);
        l=-1;//pra resetar, e assim por a entrada correta

    }//for 
    
 }//sitema para n entrar numeros invalidos , tipo 45;89;54564 horas 

 
 printf(" Vc inseriu: %02d:%02d:%02d horas \n"
        ,evento1.horario.hora
        ,evento1.horario.minuto
        ,evento1.horario.segundo);
      
//a entrada das datas 
printf("digite o dia:\n");
scanf("%d",&evento1.data.dia);
printf("digite o mês: \n");
scanf("%d",&evento1.data.mes);
printf("digite o ano:\n");
scanf("%d",&evento1.data.ano);


 for (l = 0; l <1; l++)  
 {
    
   if (evento1.data.dia >= 32 || evento1.data.mes >= 13  ) 
   {
     printf("digite o dia:\n");
     scanf("%i",&evento1.data.dia);
     printf("digite o mês: \n");
     scanf("%i",&evento1.data.mes);
     printf("digite o ano:\n");
     scanf("%i",&evento1.data.ano);
     l=-1;//pra resetar, e assim por a entrada correta

   }//for 
    
 }//sitema para n entrar numeros invalidos , tipo 45/89/54564 horas 


printf(" Vc inseriu a data:  %02d/%02d/%04d"
         ,evento1.data.dia
         ,evento1.data.mes
         ,evento1.data.ano);

setbuf(stdin,NULL);// limpam o lixo de todo scanf f acima
printf("digite o local onde vc ira:\n");
fgets(evento1.local,20,stdin);
evento1.local[strcspn(evento1.local,"\n")]=0;
setbuf(stdin,NULL);// limpa o fgets acima


printf("descreva o local onde vc ira:\n");
fgets(evento1.descricao,50,stdin);
evento1.descricao[strcspn(evento1.descricao,"\n")]=0;
setbuf(stdin,NULL);//limpa o fgets acima

printf("vc marco de ir para %s no dia %02i/%02i/%04i as %02i:%02i:%02i horas, o lugar pode pode ser descrito como:\n %s "
,evento1.local,
evento1.data.dia,
evento1.data.mes,
evento1.data.ano,
evento1.horario.hora,
evento1.horario.minuto,
evento1.horario.segundo,
evento1.descricao);

   
 return 0;
}