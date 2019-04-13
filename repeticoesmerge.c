#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int p, int q, int r) {

    int *temp, tam, p1, p2, i, j, k;
    int fim1 = 0, fim2 = 0;

    tam = r-p+1;
    p1 = p;
    p2 = q+1;
    temp = (int *) malloc(tam * sizeof(int));

    int numeroAtual, contagemNumero;

    if (temp != NULL) {
        for (i = 0; i < tam; i++) {
            if (!fim1 && !fim2) {
                if (A[p1] < A[p2])
                    temp[i] = A[p1++];
                else
                    temp[i] = A[p2++];

                if (temp[i] == numeroAtual) {
                    contagemNumero++;
                } else {
                    printf("Número: %d \t Quantidade: %d \n", numeroAtual, contagemNumero);
                    contagemNumero = 0;
                    numeroAtual = temp[i];

                }

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
        }
    }
    free(temp);
}

void mergesort(int A[], int p, int r) {

    int q;

    if (p < r) {
        q = (int) (p+r)/2;
        mergesort(A, p, q);
        mergesort(A, q+1, r);
        merge(A,p,q,r);
    }
}

void mostra(int A[], int tam) {
    int i;
    for (i=0;i<tam;i++)
        printf("[%i]\t= %i\n", i, A[i]);
}

void main() {

    int i, tam, aux;
    int vetor[] = {17, 42, 9, 7, 33, 87, 7, 92, 7, 25, 12, 7, 19, 62, 7, 48, 7, 16, 7};
    tam = sizeof(vetor)/sizeof(int);

    //mostra(vetor, tam);
    mergesort(vetor, 0, tam);

    tam = sizeof(vetor)/sizeof(int);
    mostra(vetor, tam);


}
