#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <time.h> //para calculo de tempo

int *vetor;
int op, check = 0, imprimir = 0;
double diferenca;
time_t t1, t2;
int N;
FILE *f;

void merge(int *vetor, int inicio, int meio, int fim, int tamanhoVetor) {

    int *temp, tamanho, p1, p2, i, j, k;
    int fim1 = 0, fim2 = 0, contar = 1;

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
                if (vetor[k] == vetor[k-1])
                    contar++;
                else {
                    //if (imprimir) printf("Num: %d Cont: %d\n", vetor[k-1], contador);
                    if (imprimir) printf("v[%d] = %d \t Ocorrências: %d\n", k-1, vetor[k-1], contar);
                    contar = 1;
                }
            }
        }
        if ((tamanho == tamanhoVetor))
            //if (imprimir) printf("Num: %d Cont: %d\n", vetor[k-1], contador);
            if (imprimir) printf("v[%d] = %d \t Ocorrências: %d\n", k-1, vetor[k-1], contar);
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

void executaOperacaoTrivial(int *vetor) {
    int i, j, contar = 0;
    if (imprimir) printf("\nVetor de Inteiros:\n\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            if (vetor[i] == vetor[j])
                contar++;
        //if (imprimir) printf("O numero de vezes que o elemento %d e que esta na posicao vetor[%d] aparece e: %d\n", vetor[i], i, contar);
        if (imprimir) printf("v[%d] = %d \t Ocorrências: %d\n", i, vetor[i], contar);
        contar = 0;
    }
    return;
}

void executaOperacaoComMergeSort(int *vetor) {
    mergesort(vetor, 0, N - 1, N);
    return;
}

int preencheVetorAleatoriamente(int N) {
    for (int i = 0; i < N; i++)
        vetor[i] = rand() % N;
}

int imprimirVetorInteiros(int *vetor) {
    printf("\nVetor de Inteiros:\n\n");
    for (int i = 0; i < N; i++)
        printf("v[%d] = %d\n", i, vetor[i]);
}

void imprimirTempo(time_t tempo) {
    //printf("N:%d\tTempo:%.3f\n", N, (float)tempo/CLOCKS_PER_SEC);
    fprintf(f, "N:%d\tTempo:%.3f\n", N, (float)tempo/CLOCKS_PER_SEC);
    //fprintf(f, "A character: %c\n", c);
}

void alocaVetor() {
    free(vetor);
    vetor = (int *) malloc(N * sizeof(int));
}


void testar(int size) {
    N = size;
    alocaVetor();
    preencheVetorAleatoriamente(N);
    imprimir = 0;
    t1 = clock();
    executaOperacaoTrivial(vetor);
    t2 = clock();
    diferenca = t2 - t1;
    imprimirTempo(diferenca);
}

int main() {

    f = fopen("file.txt", "wb");


    setlocale(LC_ALL,"");
    srand(time(NULL));

    for (int j = 0; j <= 100000; j = j + 10000) {
        testar(j);
    }

    for (int j = 100000; j <= 1000000; j = j + 100000) {
        testar(j);
    }

    for (int j = 1000000; j <= 10000000; j = j + 1000000) {
        testar(j);
    }

    fclose(f);

    return (1);
}
