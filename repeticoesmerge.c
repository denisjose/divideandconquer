#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int vetor[], int inicio, int meio, int fim, int tamanhototal) {

    int contagem = 0;
    int numero = 0;

    int *temp, tamanho, p1, p2, i, j, k;
    int fim1 = 0, fim2 = 0;

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

                if (tamanho == tamanhototal) {
                    if (temp[i] == numero) {
                        contagem++;
                    } else {
                        numero = temp[i];
                        contagem = 1;
                    }
                    printf("Numero: %d Contagem: %d\n", numero, contagem);
                }

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
        }
        printf("\n");
    }
    free(temp);
}

void mergesort(int vetor[], int inicio, int fim, int tamanhototal) {

    if (inicio < fim) {
        int meio = floor((inicio+fim)/2);
        mergesort(vetor, inicio, meio, tamanhototal);
        mergesort(vetor, meio+1, fim, tamanhototal);
        merge(vetor, inicio, meio, fim, tamanhototal);
    }

}

void mostra(int A[], int tam) {

    for (int i=0; i < tam; i++)
        //printf("[%d]\t= %d\n", i, A[i]);
        printf("%d ", A[i]);
    printf("\n");

}

void main() {

    int vetor[] = {17, 42, 9, 19, 33, 87, 7, 92, 42, 25, 12, 7, 42, 19, 62, 7, 48, 7, 16, 7};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);

    printf("VETOR INICIAL: ");
    mostra(vetor, tamanho);

    mergesort(vetor, 0, tamanho - 1, tamanho);

    printf("VETOR ORDENADO: ");
    mostra(vetor, tamanho);

}
