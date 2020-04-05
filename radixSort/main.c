#include <stdio.h>
#include <stdlib.h>

//void radixSort();
void radixSort(int vetor[], int tamanho);

#define TAMANHO(X) (sizeof(X) / sizeof(X[0]))
int vetor[] = {109,2,753,7,55,11,6};//vetor a ser ordenado
int maior;

int main()
{
    maior = vetor[0];
    radixSort(vetor, 7);
    printf("VETOR ORDENADO \n ");
    for(int i = 0; i < TAMANHO(vetor); i++){
       printf("%d, ", vetor[i]);
    }
    return 0;
    printf("\n ");
}

void radixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}
