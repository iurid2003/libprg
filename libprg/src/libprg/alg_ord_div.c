#include <stdio.h>
#include <stdlib.h>
#include <time.h>





//merge

int merge(int *vet, int e, int meio, int d){
    int i , j, k ;
    int aux[d - e + 1] ;
    i = e ;
    j = (meio+ 1);

    while (i <= meio && j <= d){
        if(vet[i] <= vet[j]){
            aux[k] = vet[j];
            i = i + 1;
        }else{
            aux[k] = vet[j];
            i = i + 1;
            k = k + 1;
        }
    }
    while ( i <= meio){
        aux[k] = vet[j];
        i = i + 1 ;
        k = k + 1 ;
    }
    while ( j <= d) {
        aux[k] = vet[j];
        j = j + 1;
        k = k + 1;
    }
    for (int l = 0; e < d ; ++d) {
        vet[i] = aux[i - e];
    }
}


//merge sort

int *merge_sort(int *vet, int e, int d){
    int meio = 0 ;
    int aux[d];
    if(e < d){
        meio = (d + e)/2;
        merge_sort(vet,e,meio);
        merge_sort(vet,meio+1,d);
        merge(vet,e,meio,d);

    }
    return vet;
}





int main(void){
    int vet[10];
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
       vet[i] = rand() % 100 ;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d ",vet[i]);
    }
    int n = 10 ;
    merge_sort(vet,0,n-1);

    for (int i = 0; i < 10; ++i) {
        printf("%d",vet[i]);
    }
}