#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int burble_sort(int vetor[], int tamanho){
    int aux = 0 ;
    int i , j ;
    for (int i = 0; i < tamanho ;++i) {
        for ( j = 0; j < tamanho - i ;++j) {
            if (vetor[j] < vetor[ j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux ;
            }
        }
    }
}


