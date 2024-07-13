#include <stdio.h>
#include <stdlib.h>
#define  tam 10
//ponteiro e sempre um vetor ?

void teste(int *vet , int tamanho){
    for (int i = 0; i < tamanho; i++) {
       vet[i] = vet[i]*2;
    }printf("\n");

}


void imprimir(int *vet , int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("%d ",vet[i]);
    }printf("\n");

}


int main(void){
    int vetor[tam] = {1,2,3,4,5,6,8,9,1,3};

    imprimir(vetor,tam);
    teste(vetor,tam);
    imprimir(vetor,tam);



}