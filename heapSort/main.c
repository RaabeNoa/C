#include <stdio.h>
#include <stdlib.h>

int vetor[] = {23,13,29,11,17,21,19};
#define TAMANHO(X) (sizeof(X) / sizeof(X[0]))

int heapfy();
int print_vetor();
int trocar();

int main()
{
    heapfy();
    return 0;
}

int print_vetor()
{
    for(int j=0; j < TAMANHO(vetor); j++)
    {
        printf("%d, ", vetor[j]);
    }
    printf(" \n");
    return 0;
}

int trocar(int pos_filho, int pos_pai)
{
     int aux = vetor[pos_filho];
     vetor[pos_filho] = vetor[pos_pai];
     vetor[pos_pai] = aux;
}
int heapfy()
{
    int pai, esq, dir, pos_pai = -1;
    int pos_esq = -1;
    int pos_dir = -1;
    print_vetor();
    for(int i=TAMANHO(vetor) - 1; i>0; i-=2)
    {
        pos_pai = (i-1)/2;
        pos_esq = 2*pos_pai + 1;
        pos_dir = 2*pos_pai + 2;
        if(vetor[pos_dir] < vetor[pos_pai])
        {
            trocar(pos_dir,pos_pai);
            print_vetor();
            heapfy();
        }

        if(vetor[pos_esq] < vetor[pos_pai])
        {
            trocar(pos_esq, pos_pai);
            print_vetor();
            heapfy();
        }
    }
}
