
#include "libprg/libprg.h"

 typedef struct fila{
    int valor ;
    struct  fila * proximo ;
}Fila;



void enqueue(Fila ** fila_a , int n) {
    int aux ;
    Fila *novo = malloc(sizeof(Fila));
    if(novo){
        novo->valor = n ;
        novo->proximo = NULL ;

    }else if(*fila_a = NULL){
           *fila_a = novo ;
    }else{

    }
        printf("Erro Ao Alocar memoria ");
    }
}











