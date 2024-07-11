#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void burble_sort(int vetor[], int tamanho){
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

void decrescente(int *vetor , int tamanho){
    for (int i = 0; i < 5; ++i) {
        printf("%d, ",vetor[i]);
    }
}

void crescente(int *vetor, int tamanho){
    for (int i = tamanho; tamanho > -1 ; --i) {
        printf("%d, ",vetor[i]);
    }
}

int *insertion_sort(int *vetor, int tamanho){
    int chave = 0 ;
    int i , j = 0 ;
    for ( i = 1; i < tamanho ; i++) {
        chave = vetor[i];
        j = i - 1  ;
        while (j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j] ;
            j = j - 1 ;

        }
        vetor[j + 1] = chave ;
    }
    return vetor ;
}

void selection_sort(int *vet, int tamanho) {
    int min = 0;
    int aux = 0;
    for (int i = 0; i < tamanho ; i++) {
        min = i;
        for (int j = i + 1; j < tamanho ; ++j) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        if (i != min) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}

