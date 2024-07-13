#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void maior_menor(int *vet , int tam , int *maior , int *menor){
    *menor = *vet ;
    *maior = *vet;
    for (int i = 0; i < 10; ++i) {
         if(*menor > vet[i]){
             *menor = vet[i];
         }
        if(*maior < vet[i]){
            * maior = vet[i];
        }
    }
}


int main(void){
    srand(time(NULL));

    int vet[10] = {0};
    int maior = 0 ;
    int menor = 100 ;

    for (int i = 0; i < 10; i++) {
        vet[i] = rand() % 100 ;
    }

    maior_menor(vet,10,&maior,&menor);
    for (int i = 0; i < 10; i++) {
        printf("%d ",vet[i]);
    }printf("\n");
    printf(" Maior : %d",maior);
    printf(" Menor : %d",menor);


 return 0 ;

}