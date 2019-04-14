#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *vetor, int inicio, int meio, int fim, int tamanhoVetor) {

    int *temp, tamanho, p1, p2, i, j, k;
    int fim1 = 0, fim2 = 0, contador = 0, numero = 0;

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

                if (tamanho == tamanhoVetor) {
                    if (temp[i] == numero)
                        contador++;
                    else {
                        printf("Numero: %d contador: %d\n", numero, contador);
                        numero = temp[i];
                        contador = 1;
                    }
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

void mostra(int vetor[], int tam) {

    for (int i=0; i < tam; i++)
        //printf("[%d]\t= %d\n", i, A[i]);
        printf("%d ", vetor[i]);
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
