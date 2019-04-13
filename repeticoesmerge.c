#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int p, int q, int r) {

    int *temp, tam, p1, p2, i, j, k;
    int fim1 = 0, fim2 = 0;

    tam = r-p+1;
    p1 = p;
    p2 = q+1;
    temp = (int *) malloc(tam * sizeof(int));

    if (temp != NULL) {
        for (i = 0; i < tam; i++) {
            if (!fim1 && !fim2) {
                if (A[p1] < A[p2])
                    temp[i] = A[p1++];
                else
                    temp[i] = A[p2++];
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
    int vetor[] = {17, 42, 9, 33, 87, 92, 25, 12, 19, 62, 48, 16};
    tam = sizeof(vetor)/sizeof(int);

    mostra(vetor, tam);
    mergesort(vetor, 0, tam);

    tam = sizeof(vetor)/sizeof(int);
    mostra(vetor, tam);

    int cont = 0;
    int j;

    for (i = j =0; i < tam-1; i++) {
        if (vetor[i] != vetor[j])
            vetor[++j] = vetor[i];
        else {
            printf("Contou >> i=%i >> j=%i >> vetor[i]:%i >> vetor[j]:%i \n", i, j, vetor[i], vetor[j]);
            ++cont;
        }
    }

    printf("Repetições: %i \n", cont);

}
