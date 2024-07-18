#include <stdio.h>
#include <stdlib.h>
#include <time.h>





//merge

void merge(int *vet, int e, int meio, int direita) {
    int aux[direita - e + 1];
    int i = e;
    int j = meio + 1;
    int k = 0;

    while (i <= meio && j <= direita) {
        if (vet[i] <= vet[j]) {
            aux[k++] = vet[i++];
        } else {
            aux[k++] = vet[j++];
        }
    }

    while (i <= meio) {
        aux[k++] = vet[i++];
    }

    while (j <= direita) {
        aux[k++] = vet[j++];
    }

    // Copia os elementos ordenados de aux de volta para vet
    for (int l = e; l <= direita; ++l) {
        vet[l] = aux[l - e];
    }
}



//merge sort
void merge_sort(int *vet, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort(vet, esquerda, meio); // Ordena a metade esquerda do array
        merge_sort(vet, meio + 1, direita); // Ordena a metade direita do array

        merge(vet, esquerda, meio, direita); // Combina as duas metades ordenadas
    }
}


//quick-short

void troca_pos(int **vet, int **vet2) {
    int *aux = *vet;  // Store the value of vet in aux
    *vet = *vet2;     // Point vet to the same location as vet2
    *vet2 = aux;      // Point vet2 to the original location of vet
}



int particiona(int *vet, int inicio, int fim)
{
    int pivo = vet[fim];
    int i = inicio - 1 ;
    for (int j = 0; inicio <= fim -1 ; ++i) {
        if( vet[j] <= pivo){
            i = i + 1 ;
            troca_pos(&vet[i],&vet[j]);
        }
    }
    i = i + 1 ;
    troca_pos(&vet[i],&vet[fim]);
    return i ;
}

void quicksort(int *vet, int inicio, int fim){
    int p ;
    if(inicio < fim){
        p = particiona(vet,inicio,fim);
        quicksort(vet,inicio,p-1);
        quicksort(vet,p + 1,fim);
    }
}


int main(void){
    int vet[10];
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
       vet[i] = rand() % 100 ;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d ",vet[i]);
    }printf("\n");
    int n = 10 ;
    quicksort(vet,0,n);

    for (int i = 0; i < 10; ++i) {
        printf("%d ",vet[i]);
    }
}