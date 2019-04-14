#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int A[], int p, int q, int r) {


int contagem = 0;
int numero = 0;
    int *temp, tam, p1, p2, i, j, k;
    int fim1 = 0, fim2 = 0;

    tam = r-p+1;
    p1 = p;
    p2 = q+1;
    temp = (int *) malloc(tam * sizeof(int));

    if (temp != NULL) {
        for (i=0; i < tam; i++) {
            if (!fim1 && !fim2) {
                if (A[p1] < A[p2])
                    temp[i] = A[p1++];
                else
                    temp[i] = A[p2++];

                if (temp[i] == numero) {
                    contagem++;
                } else {
                    numero = temp[i];
                    contagem = 1;
                }
                //printf("Numero: %d Contagem: %d\n", numero, contagem);

                if (p1 > q)
                    fim1 = 1;
                if (p2 > r)
                    fim2 = 1;
            }
            else {
                if (!fim1)
                    temp[i] = A[p1++];
                else
                    temp[i] = A[p2++];
            }

        }
        for (j=0, k=p; j<tam; j++, k++) {
            A[k] = temp[j];
            printf("Teste\n");
        }
    }
    free(temp);
}

void mergesort(int A[], int p, int r) {

    if (p < r) {
        int q = floor((p+r)/2);
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A, p, q, r);
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
    int tam = sizeof(vetor)/sizeof(vetor[0]);

    mostra(vetor, tam);
    mergesort(vetor, 0, tam - 1);
    mostra(vetor, tam);

}
