#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int *vetor;
int op, check = 0, imprimir = 0;
clock_t tempo;
int N;

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
                    if (imprimir) printf("v[%d] = %d \t Ocorr�ncias: %d\n", k-1, vetor[k-1], contar);
                    contar = 1;
                }
            }
        }
        if ((tamanho == tamanhoVetor))
            if (imprimir) printf("v[%d] = %d \t Ocorr�ncias: %d\n", k-1, vetor[k-1], contar);
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
        if (imprimir) printf("v[%d] = %d \t Ocorr�ncias: %d\n", i, vetor[i], contar);
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
    return 1;
}

int imprimirVetorInteiros(int *vetor) {
    printf("\nVetor de Inteiros:\n\n");
    for (int i = 0; i < N; i++)
        printf("v[%d] = %d\n", i, vetor[i]);
}

void imprimirTempo(time_t tempo) {
    printf("\nO tempo gasto foi %.3f: segundos.\n", (float)tempo/CLOCKS_PER_SEC);
}

void alocaVetor() {
    free(vetor);
    vetor = (int*) malloc(sizeof(int) * N);
}

void teste(int n) {
    clock_t t_trivial, t_mergesort;

    N = n;
    alocaVetor();
    preencheVetorAleatoriamente(N);
    imprimir = 0;
    t_trivial = clock();
    executaOperacaoTrivial(vetor);
    t_trivial = clock() - t_trivial;
    t_mergesort = clock();
    executaOperacaoComMergeSort(vetor);
    t_mergesort = clock() - t_mergesort;

    // Imprime os tempos na ordem: N | Trivial | MergeSort
    printf("%d\t%.3f\t%.3f\n", N, (float)t_trivial/CLOCKS_PER_SEC, (float)t_mergesort/CLOCKS_PER_SEC);
}

void testar() {
    double num = 0;
    for (int i=1; i<=5; i++) {
        for (int j=1; j<10; j++) {
            num = j * (pow(10,i));
            printf("num:%.f (%d,%d)\n", num, i, j);
            //teste(num);
        }
    }
}

int main() {
    setlocale(LC_ALL,"");
    printf("Informe o tamanho do vetor: \n");
    scanf("%d", &N);
    alocaVetor();
    srand(time(NULL));
    /*  srand(time(NULL)) objetiva inicializar o gerador de n�meros aleat�rios
        com o valor da fun��o time(NULL). Este por sua vez, � calculado
        como sendo o total de segundos passados desde 1 de janeiro de 1970
        at� a data atual.
        Desta forma, a cada execu��o o valor da "semente" ser� diferente.  */

    do {
        printf("\n------------------------------------MENU---------------------------------------");
        printf("\n1 - Preencher o Vetor de Inteiros");
        printf("\n2 - Imprimir o Vetor de Inteiros");
        printf("\n3 - Fazer a Contagem de ocorr�ncias pelo M�todo Trivial e IMPRIMIR");
        printf("\n4 - Fazer a Contagem de ocorr�ncias pelo M�todo Trivial sem imprimir");
        printf("\n5 - Fazer a Contagem de ocorr�ncias pelo M�todo Otimizado e IMPRIMIR");
        printf("\n6 - Fazer a Contagem de ocorr�ncias pelo M�todo Otimizado sem imprimir");
        printf("\n7 - Alterar o valor de N (atual N = %d)", N);
        printf("\n8 - Realizar testes");
        printf("\n9 - Sair.");
        printf("\n-------------------------------------------------------------------------------");
        printf("\nEntre com a op��o desejada: ");
        scanf("%d", &op);
        system("cls");
        fflush(stdin);
        switch (op) {
        case 1:
            tempo = clock(); //inicio da contagem do tempo para realiza��o da opera��o.
            //Obs: Aqui s� a titulo de exemplo vai depender do operador ditar os n�meros do vetor
            if (preencheVetorAleatoriamente(N)) printf("Vetor devidamente preenchido");
            tempo = clock() - tempo;

            imprimirTempo(tempo);
            check++;
            break;

        case 2:
            if (check > 0) {
                tempo = clock();
                imprimirVetorInteiros(vetor);
                tempo = clock() - tempo;

                imprimirTempo(tempo);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 3:
            if (check > 0) {
                tempo = clock();
                imprimir = 1;
                executaOperacaoTrivial(vetor);
                tempo = clock() - tempo;

                imprimirTempo(tempo);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 4:
            if (check > 0) {
                tempo = clock();
                imprimir = 0;
                executaOperacaoTrivial(vetor);
                tempo = clock() - tempo;

                imprimirTempo(tempo);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 5:
            if (check > 0) {
                tempo = clock();
                imprimir = 1;
                executaOperacaoComMergeSort(vetor);
                tempo = clock() - tempo;

                imprimirTempo(tempo);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 6:
            if (check > 0) {
                tempo = clock();
                imprimir = 0;
                executaOperacaoComMergeSort(vetor);
                tempo = clock() - tempo;

                imprimirTempo(tempo);
            } else
                printf("\nPrecisa-se preencher o Vetor de Inteiros. Digite 1\n");
            break;

        case 7:
            printf("Informe o tamanho do vetor: \n");
            scanf("%d", &N);
            check = 0;
            alocaVetor();
            break;

        case 8:
            testar();
            break;

        case 9:
            exit(0);
            break;

        default:
            printf("Op��o inv�lida");
            op = 1;
            break;
        }
    } while (op > 0 || op < 10);

    getch();

    return (1);
}
