#include <stdio.h>
#include <stdlib.h>

//Alocacao dinamica de memoria
/*
  Retorna um ponteiro para a regiao de memoria
 */


int main(void){
    int *x;
    x = malloc(sizeof(int));
    if(x){
        printf("Memoria alocada\n");
        printf("x : %d\n",*x);
        *x = 50 ;
        printf("x : %d\n",*x);
    }else{
        printf("Erro ao Alocar memoria");
    }




    return 0 ;
}

