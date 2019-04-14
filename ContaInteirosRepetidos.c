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
        printf("\n3 - Fazer a Contagem de ocorrencias pelo Metodo Trivial e IMPRIMIR.");
        printf("\n4 - Fazer a Contagem de ocorrencias pelo Metodo Trivial sem imprimir.");
        printf("\n5 - Fazer a Contagem de ocorrencias pelo Metodo Otimizado e IMPRIMIR.");
        printf("\n6 - Fazer a Contagem de ocorrencias pelo Metodo Otimizado sem imprimir.");
        printf("\n7 - Alterar o valor de N.");
        printf("\n8 - Sair.");
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

                case 4 : if (check>0){
                            time(&t1);
                            executaOperacaoTrivialsemIMPRESSAO(vetor);
                            time(&t2);
                            diferenca = difftime(t2,t1); //diferença em segundos
                            printf("\nO tempo gasto foi %f: segundos.\n",diferenca);
                            }
                         else
                            printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
                         break;

                case 5 : if (check>0)
                            executaOperacaoComMergeSort(vetor);
                         else
                            printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
                         break;

                 case 6 : if (check>0)
                            executaOperacaoComMergeSort(vetor);
                         else
                            printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
                         break;

                case 7 : printf("Digite o tamanho do vetor: \n");
                         scanf("%d",&N);
                         check=0;
                         vetor = (int*)malloc(N * sizeof(int));
                         break;

                case 8 : exit(0);
                         break;

                default : printf("Opcao invalida");
                          op = 1;
                          break;
        }
    } while (op >0 || op <9);

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

void executaOperacaoTrivialsemIMPRESSAO(int* vetor){
    int i, j, contar = 0;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(vetor[i]==vetor[j]){
                contar++;
            }
        }
       // printf("O numero de vezes que o elemento %d e que esta na posicao vetor[%d] aparece e: %d\n",vetor[i],i,contar);
        contar=0;
    }
    return;
}

void executaOperacaoComMergeSort(int* vetor){
    Mergesort(vetor,0,N-1);
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

 void Merge(int* vetor, int inicio, int meio, int fim){
    int esq = inicio, dir = meio + 1, aux = 0, tamanho = fim - inicio + 1;
    int *vetAux;
    vetAux = (int*)malloc(tamanho * sizeof(int));

    while(esq <= meio && dir <= fim){
        if(vetor[esq] < vetor[dir]) {
            vetAux[aux] = vetor[esq];
            esq++;
        } else {
            vetAux[aux] = vetor[dir];
            dir++;
        }
        aux++;
    }

    while(esq <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[aux] = vetor[esq];
        aux++;
        esq++;
    }

    while(dir <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[aux] = vetor[dir];
        aux++;
        dir++;
    }

    for(aux = inicio; aux <= fim; aux++){    //Move os elementos de volta para o vetor original
        vetor[aux] = vetAux[aux-inicio];
    }

    free(vetAux);
}

void Mergesort(int* vetor, int inicio, int fim)
{ int meio;
  if (inicio < fim)
  { meio = (inicio + fim) / 2;
    Mergesort(vetor, inicio, meio);
    Mergesort(vetor, meio + 1, fim);
    Merge(vetor,  inicio,  meio, fim);
  }
 }

