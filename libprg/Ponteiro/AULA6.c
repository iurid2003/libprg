#include <stdio.h>
#include <stdlib.h>
#define  tam 10
//ponteiro e sempre um vetor ?

void imprimir(int *vet , int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("%d ",*(vet + i));
    }printf("\n");

}


int main(void){
    int vetor[tam] = {1,2,3,4,5,6,8,9,1,3};

    imprimir(vetor,tam);


}