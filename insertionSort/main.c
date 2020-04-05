#include <stdio.h>
#include <stdlib.h>

int insertionSort();

#define TAMANHO(X) (sizeof(X) / sizeof(X[0]))
int vetor[] = {9,2,3,7,5,1,6};//vetor a ser ordenado

int main()
{
    insertionSort();
    printf("VETOR ORDENADO \n ");
    for(int i = 0; i < TAMANHO(vetor); i++){
       printf("%d, ", vetor[i]);
    }
    printf("\n");
    return 0;
}

int insertionSort(){
    int aux = 0;
    int j;
    // for começa de 0 pq o primeiro item já está ordenado
    for(int i = 1; i < TAMANHO(vetor); i++){
        j = i - 1;
        while (vetor[i] < vetor[j] && j >= 0){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            j--; i--;
        }
    }
}
