

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

/*Faça um programa que gere 100 números aleatórios. Esse
programa deverá, em seguida,armazenar esses números em um
arquivo binário.
*/



int main (){


  int aleatorio [100];


  FILE *arquivo = fopen("arquivo.bin","wb"); //Abre o arquivo , coloquei assim ja q vai criar direto no path 

if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

//Realiza a escrita utilizando o fprintf
 
  for (int i = 0; i < 100; i++)
  {
    aleatorio[i] =rand() % 100;
  }
 fwrite(aleatorio, sizeof(int),100,arquivo);
  
  
  fclose(arquivo);

  // Abre o arquivo usando o comando do sistema, dependendo do sistema operacional . Dessa forma facilita o usuario acha o arquivo 
    #ifdef _WIN32
        system("start arquivo.bin"); //windows
    #elif __linux__
        system("xdg-open arquivo.bin"); //linux
    #else
        printf("Sistema operacional não suportado.");
    #endif
//eu lembro que o senhor tinha ensinado na aula como ver o sistema operacional do usuario através de if.
// Eu n lembrava qual era o metodo q o senhor tinha dito dai peguei esse "ifdef" na net , eu entendi a logica meio q por cima , dai fiz assim pq achei q ficava mais pratico pra quem usar.
//mas pelo q eu lembro n parece muito diferento do metodo q o senhor mostrou em aula.
  return 0;
}










