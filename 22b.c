

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//Elabore um programa que leia um arquivo binário contendo 100 números. Mostre na tela a soma desses números



// talvez eu compliquei um pouco mas meio q queria testar em case pra me acustamar usar essa função de arquivos
// ja que provavelmente era bem mais facil pedir o arquivo se n ouvesse o programa ja gerava automaticamente o arquivo com o primeiro nome citado

int main(){

int numeros[100];
int soma = 0 ;
int opcao;
char palavra[51];


            printf("Digite o nome do arquivo que deseja abrir\n");
            setbuf(stdin, NULL);
            fgets(palavra, 50, stdin);
            palavra[strcspn(palavra, "\n")] = '\0';
            setbuf(stdin, NULL);

 FILE *arquivo = fopen(palavra,"rb"); //Abre o arquivo
   if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
      



        printf("Escolha uma opção:\n");
        printf("1 - crir o arquivo.bin para que o programa leia\n");
        printf("2 - sair \n");

        scanf("%d", &opcao);

        setbuf(stdin, NULL);
        switch (opcao) {
            case 1:

                printf("Você escolheu a Opção 1.\n");
                printf("sera gerado um arquivo.bin de mesmo nome com 100 numeros aleatórios\n ");
                arquivo = fopen(palavra,"wb"); //Abre o arquivo / cria o arquivo
                int aleatorio [100];//eu sofri pra entender q essa variavel não podia ser a primeira coisa lida no case 
                //ja que antes tem coisa para ser lida fora da case como a string palavra 
                
                for (int i = 0; i < 100; i++)
                {
                    aleatorio[i] =rand() % 100;
                }//for onde vetor aleatorio recebe os numeros aleatórios de 1 a 100 neste caso.

                //Realiza a escrita utilizando o fwrite
                fwrite(aleatorio, sizeof(int),100,arquivo);
                printf("arquivo gerado com sucesso!\n\n");

                fclose(arquivo);
                arquivo = fopen("arquivo.bin", "rb"); // Abre o arquivo
    
                break;

            case 2:
            
            
                printf("voce escolheu a opção 2");
                printf("o programa ser fechado automaticamente");



                fclose(arquivo);
                return 0;  // Encerra o programa
                break;
                

            default:
                printf("Opção inválida.\n");
                break;
        }//case

   }//if

 fread(numeros,sizeof(int),100,arquivo);// transfere kd um dos numeros do arquivo para o vetor numeros

 for(int l=0; l <100; l++){

    soma = numeros[l]+soma;

 }//for onde é realizado soma de todos numeros
 
printf("O resultado é %d \n",soma);


 fclose(arquivo);

    return 0;
}//main




