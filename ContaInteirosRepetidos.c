#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h> //para calculo de tempo

int * vetor;
int op, check = 0;
double diferenca;
time_t t1, t2;
int N;

void merge(int *vetor, int inicio, int meio, int fim, int tamanhoVetor) {

    int *temp, tamanho, p1, p2, i, j, k;
    int fim1 = 0, fim2 = 0, contador = 1;

    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho * sizeof(int));

    if (temp != NULL) {
        for (i=0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vetor[p1] < vetor[p2])
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];

                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else {
                if (!fim1)
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
            }
        }

        for (j=0, k=inicio; j<tamanho; j++, k++) {
            vetor[k] = temp[j];
            if ((tamanho == tamanhoVetor) && (k > 0)) {
                if (vetor[k] == vetor[k-1]) {
                    contador++;
                }
                else {
                    //printf("Num: %d Cont: %d\n", vetor[k-1], contador);
                    contador = 1;
                }
            }
        }
        if ((tamanho == tamanhoVetor)) {
            //printf("Num: %d Cont: %d\n", vetor[k-1], contador);
        }
    }
    free(temp);
}

void mergesort(int *vetor, int inicio, int fim, int tamanhoVetor) {

    if (inicio < fim) {
        int meio = floor((inicio+fim)/2);
        mergesort(vetor, inicio, meio, tamanhoVetor);
        mergesort(vetor, meio+1, fim, tamanhoVetor);
        merge(vetor, inicio, meio, fim, tamanhoVetor);
    }

}

void executaOperacaoTrivial(int * vetor, int imprimir) {

    int i, j, contar = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (vetor[i] == vetor[j]) {
                contar++;
            }
        }
        if (imprimir) printf("O numero de vezes que o elemento %d e que esta na posicao vetor[%d] aparece e: %d\n", vetor[i], i, contar);
        contar = 0;
    }
    return;

}

void executaOperacaoComMergeSort(int * vetor) {

    mergesort(vetor, 0, N - 1, N);
    return;

}

int preencheVetorAleatoriamente(int N) {
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % N;
        //printf("v[%d] = %d\n", i, vetor[i]);
    }
    printf("Vetor devidamente preenchido");
}

int imprimirVetorInteiros(int * vetor) {

    printf("\nVetor de Inteiros:\n\n");
    for (int i = 0; i < N; i++) {
        //vetor[i]= rand() % N;
        printf("v[%d] = %d\n", i, vetor[i]);
    }

}

int main() {

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &N);

    vetor = (int * ) malloc(N * sizeof(int));

    srand(time(NULL));
    /*  srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
        com o valor da função time(NULL). Este por sua vez, é calculado
        como sendo o total de segundos passados desde 1 de janeiro de 1970
        até a data atual.
        Desta forma, a cada execução o valor da "semente" será diferente.  */

    do {
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
        switch (op) {
        case 1:
            time(&t1); //inicio da contagem do tempo para realização da operação.
            //Obs: Aqui só a titulo de exemplo vai depender do operador ditar os números do vetor
            preencheVetorAleatoriamente(N);
            time(&t2); //fim da contagem do tempo da operação
            diferenca = difftime(t2, t1); //diferença em segundos
            printf("\nO tempo gasto foi %f: segundos.\n", diferenca);
            check++;
            break;

        case 2:
            if (check > 0) {
                time(&t1);
                imprimirVetorInteiros(vetor);
                time(&t2);
                diferenca = difftime(t2, t1); //diferença em segundos
                printf("\nO tempo gasto foi %f: segundos.\n", diferenca);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 3:
            if (check > 0) {
                time(&t1);
                executaOperacaoTrivial(vetor, 1);
                time(&t2);
                diferenca = difftime(t2, t1); //diferença em segundos
                printf("\nO tempo gasto foi %f: segundos.\n", diferenca);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 4:
            if (check > 0) {
                time(&t1);
                executaOperacaoTrivial(vetor, 0);
                time(&t2);
                diferenca = difftime(t2, t1); //diferença em segundos
                printf("\nO tempo gasto foi %f: segundos.\n", diferenca);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 5:
            if (check > 0) {
                time(&t1);
                executaOperacaoComMergeSort(vetor);
                time(&t2);
                diferenca = difftime(t2, t1); //diferença em segundos
                imprimirVetorInteiros(vetor);
                printf("\nO tempo gasto foi %f: segundos.\n", diferenca);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 6:
            if (check > 0) {
                time(&t1);
                executaOperacaoComMergeSort(vetor);
                time(&t2);
                diferenca = difftime(t2, t1); //diferença em segundos
                printf("\nO tempo gasto foi %f: segundos.\n", diferenca);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 7:
            printf("Digite o tamanho do vetor: \n");
            scanf("%d", &N);
            check = 0;
            vetor = (int * ) malloc(N * sizeof(int));
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("Opcao invalida");
            op = 1;
            break;
        }
    } while (op > 0 || op < 9);

    getch();

    return (1);

}
