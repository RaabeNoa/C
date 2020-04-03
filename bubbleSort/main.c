#include <stdio.h>
#include <stdlib.h>

int bbSort();

#define TAMANHO(X) (sizeof(X) / sizeof(X[0]))
int vetor[] = {9,2,3,7,2,5,1,6,7,11,1,3};//vetor a ser ordenado


int main()
{
    bbSort();
    printf("VETOR ORDENADO \n ");
    for(int i = 0; i < TAMANHO(vetor); i++){
       printf("%d, ", vetor[i]);
    }
    return 0;
}

int bbSort(){
    int aux = 0;
    for(int i = TAMANHO(vetor)-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(vetor[j] > vetor[j+1]){
                aux      = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}
