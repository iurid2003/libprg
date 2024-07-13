#include <stdio.h>
#include "stdlib.h"
#include "time.h"

int main(void){

    srand(time(NULL));
    int *vet ;

    int tam ;

    printf("Digite o tamanho do vetor : ");
    scanf("%d",&tam);

    vet = malloc(sizeof(int)*tam);
    if(vet){
        for (int i = 0; i < tam; ++i) {
            vet[i] = rand() % 100;
        }

        for (int i = 0; i < tam; ++i) {
            printf("%d ",*(vet + i));
        }

    }else{
        printf("Erro ao Alocar memoria");
    }
    return 0 ;

}


