#include <stdio.h>
#include <stdlib.h>

int vetor[] = {5,4,7,8,2,0,9,5,1,4,3,6,2,4,5,11,13,1,0,2};
#define TAMANHO(X) (sizeof(X) / sizeof(X[0]))
int chave = 0;

int insertionSort();
int buscaBinaria(int chave);

int main()
{
    int chave;
    printf("--------------------------BUSCA BINARIA-------------------------------\n");
    printf("Qual valor você gostaria de buscar?\n");
    scanf("%d", &chave);
    insertionSort();
    printf("----VETOR ORDENADO---- \n ");
    for(int i = 0; i < TAMANHO(vetor); i++){
       printf("%d, ", vetor[i]);
    }
    printf("\n----RESULTADO---- \n ");
    int resultado = buscaBinaria(chave);
    if(resultado != -1){
        printf("Chave %d encontrada na posicao %d \n", chave, resultado);
    }else{
        printf("Chave nao encontrada \n ");
    }
    return 0;
}

int buscaBinaria(int chave){
    int pos    = -1;
    int inicio = 0;
    int meio   = 0;
    int fim    = TAMANHO(vetor);
    while(inicio <= fim && pos == -1){
        meio = (fim + inicio)/2;
        if(vetor[meio] == chave){
            pos = meio;
        }
        if(vetor[meio] > chave){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }
    return pos;
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
