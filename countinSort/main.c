#include <stdio.h>
#include <stdlib.h>

void countingSort();
void calculaLimites();

#define TAMANHO(X) (sizeof(X) / sizeof(X[0]))
int entrada[] = {3,1,2,0,5,0,1};
int saida[TAMANHO(entrada)];
int maior;
int menor;

int main()
{
    maior = entrada[0];
    menor = entrada[0];
    calculaLimites();
    countingSort();
    printf("\nVETOR ORDENADO \n ");
    for(int i = 0; i < TAMANHO(entrada); i++){
       printf("%d, ", saida[i]);
    }
    printf(" \n ");
    return 0;
}

void countingSort(){
    int aux[TAMANHO(entrada)-1];
    //preenche o vetor aux com zero
    for(int i = 0; i <= maior; i++){
        aux[i] = 0;
    }
    //conta quantas vezes cada item aparece
    for(int j = 0; j < TAMANHO(entrada); j++){
        aux[entrada[j]-menor]++;
    }
    for(int j = 1; j <= maior; j++){
        aux[j] += aux[j-1];
    }
    int pos = 0;
    for(int j = TAMANHO(entrada)-1; j >= 0; j--){
        pos = entrada[j];
        saida[aux[pos]-1] = entrada[j];
        aux[pos]--;
    }
}

void calculaLimites(){
    for(int i = 1; i < TAMANHO(entrada); i++){
        if(entrada[i] > maior)
            maior = entrada[i];
        if(entrada[i] < menor)
            menor = entrada[i];
    }
    printf("\nMAIOR: %d | MENOR %d \n ", maior, menor);
}
