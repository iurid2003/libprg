#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//merge

int *merge(int *vet,int esquerda, int meio, int direita){
    int auxiliar[direita - esquerda + 1];
    int i = esquerda ;
    int j = (meio + 1);
    int k = 0 ;


    while(i <= meio && j <= direita){
        if(vet[i] <= vet[j]){
            auxiliar[k] = vet[i];
            i++;
        }else{
            auxiliar[k] = vet[j];
            j++ ;
        }
        k++;
    }

    while(i <= meio){
        auxiliar[k] = vet[i];
        i++;
        k++;
    }
    while(j <= direita){
        auxiliar[k] = vet[j];
        j++;
        k++;
    }

    for (int l = esquerda; l <= direita ; ++l) {
        vet[l]= auxiliar[l - esquerda];
    }
    return vet;
}



//merge sort
int *merge_sort(int *vet, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + ((direita - esquerda) / 2);
        // oredene as metades
        merge_sort(vet, esquerda, meio); // Ordena a metade esquerda do array
        merge_sort(vet, meio + 1, direita); // Ordena a metade direita do array

        merge(vet, esquerda, meio, direita); // Combina as duas metades ordenadas
    }
    return vet;
}







//quick-short



int particiona(int *vet, int inicio, int fim)
{
    int aux ;
    int pivo = vet[fim];
    int i = inicio - 1 ;
    for (int j = inicio; j <= (fim -1) ; ++j) {
        if( vet[j] <= pivo){
            i++;
            aux = vet[i];
            vet[i]  = vet[j];
            vet[j] = aux ;

        }
    }
    i = i + 1 ;
    aux = vet[i];
    vet[i] = vet[fim];
    vet[fim] = aux ;
    return i ;
}

int  *quicksort(int *vet, int inicio, int fim){
    int p ;
    if(inicio < fim){
        p = particiona(vet,inicio,fim);
        quicksort(vet,inicio,p-1);
        quicksort(vet,p + 1,fim);
    }
    return vet ;
}


int main(void){
    int vet[10] = {1,4,34,7,8,23,12,3,5,2};
    srand(time(NULL));


    for (int i = 0; i < 10; ++i) {
        printf("%d ",vet[i]);
    }printf("\n");
    int n = 10 ;
  (vet,0,n-1);

    quicksort(vet,0,10-1);

    for (int i = 0; i < 10; ++i) {
        printf("%d ",vet[i]);
    }


}