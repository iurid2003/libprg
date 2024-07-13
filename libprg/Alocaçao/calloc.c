#include "stdlib.h"
#include "stdio.h"

int main(void){

    int *x ;
    x = calloc(1,sizeof(int));
    if(x){
        printf("Memoria alocada\n");
        printf("x : %d\n",*x);
        *x = 50 ;
        printf("x : %d\n",*x);
    }else{
        printf("Erro ao Alocar memoria");
    }

}