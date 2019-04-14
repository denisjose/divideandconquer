#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h> //para calculo de tempo

int *vetor;
int op, check = 0;
double diferenca;
time_t t1,t2;
int N;

int main(){
    printf("Digite o tamanho do vetor: \n");
    scanf("%d",&N);

    vetor = (int*)malloc(N * sizeof(int));

    srand(time(NULL));
            /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
  com o valor da função time(NULL). Este por sua vez, é calculado
  como sendo o total de segundos passados desde 1 de janeiro de 1970
  até a data atual.
  Desta forma, a cada execução o valor da "semente" será diferente.  */

    do{
        printf("\n------------------------------------MENU---------------------------------------");
        printf("\n1 - Preencher o Vetor de Inteiros.");
        printf("\n2 - Imprimir o Vetor de Inteiros.");
        printf("\n3 - Fazer a Contagem de ocorrencias pelo Metodo Trivial.");
        printf("\n4 - Fazer a Contagem de ocorrencias pelo Metodo Otimizado.");
        printf("\n5 - Alterar o valor de N.");
        printf("\n6 - Sair.");
        printf("\n-------------------------------------------------------------------------------");
        printf("\nEntre com a opcao desejada: ");
        scanf("%d", &op);
        system("cls");
        fflush(stdin);
        switch(op) {
                case 1 : time(&t1); //inicio da contagem do tempo para realização da operação.
                                    //Obs: Aqui só a titulo de exemplo vai depender do operador ditar os números do vetor
                         preencheVetorAleatoriamente(N);
                         time(&t2); //fim da contagem do tempo da operação
                         diferenca = difftime(t2,t1); //diferença em segundos
                         printf("\nO tempo gasto foi %f: segundos.\n",diferenca);
                         check++;
                         break;

                case 2 : if (check>0){
                            time(&t1);
                            imprimirVetorInteiros(vetor);
                            time(&t2);
                            diferenca = difftime(t2,t1); //diferença em segundos
                            printf("\nO tempo gasto foi %f: segundos.\n",diferenca);
                            }
                         else
                            printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
                         break;

                case 3 : if (check>0){
                            time(&t1);
                            executaOperacaoTrivial(vetor);
                            time(&t2);
                            diferenca = difftime(t2,t1); //diferença em segundos
                            printf("\nO tempo gasto foi %f: segundos.\n",diferenca);
                            }
                         else
                            printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
                         break;

                case 4 : if (check>0)
                            executaOperacaoComMergeSort();
                         else
                            printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
                         break;

                case 5 : printf("Digite o tamanho do vetor: \n");
                         scanf("%d",&N);
                         check=0;
                         vetor = (int*)malloc(N * sizeof(int));
                         break;

                case 6 : exit(0);
                         break;

                default : printf("Opcao invalida");
                          op = 1;
                          break;
        }
    } while (op >0 || op <7);

    getch();

    return(1);
}

void executaOperacaoTrivial(int* vetor){
    int i, j, contar = 0;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(vetor[i]==vetor[j]){
                contar++;
            }
        }
        printf("O numero de vezes que o elemento %d e que esta na posicao vetor[%d] aparece e: %d\n",vetor[i],i,contar);
        contar=0;
    }
    return;
}

void executaOperacaoComMergeSort(){
    return;
}

 int preencheVetorAleatoriamente(int N){
       for(int i=0; i<N; i++){
        vetor[i]= rand() % N;
        //printf("v[%d] = %d\n", i, vetor[i]);
     }
     printf("Vetor devidamente preenchido");
 }

 int imprimirVetorInteiros(int* vetor){
     printf("\nVetor de Inteiros:\n\n");
     for(int i=0; i<N; i++){
        //vetor[i]= rand() % N;
        printf("v[%d] = %d\n", i, vetor[i]);
     }
 }


