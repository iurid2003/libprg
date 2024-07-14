#include <stdio.h>
#include <stdlib.h>


//inserir na fila

typedef struct no_f{
    int valor ;
     struct  no_f * proximo ;
}No_f;


void inserir_fila(No_f**fila, int num){
    No_f * novo , *aux = malloc(sizeof(No_f));
    if (novo){
        novo->valor = num ;
        novo->proximo = NULL;
        if (*fila == NULL){
            *fila = novo ;
        }else{
             aux = *fila ;
            while (aux->proximo){
                aux = aux->proximo ;
                aux->proximo = novo ;
            }
        }
    }else{
        printf("Erro ao alocar memoria");
    }
}

No_f * remover_da_fila(No_f ** fila){
    No_f  * remover = NULL;
    if(*fila){
        remover = *fila ;
        *fila = remover->proximo ;

    }else{
        printf("Fila Vazia");
    }
    return remover;
}


void imprimir_fila(No_f * fila){
    printf("---FILA---");
    while (fila){
        printf("%d",fila->valor);
        fila = fila->proximo ;
    }
    printf("--- FIM FILA ---");
}