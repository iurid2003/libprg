#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Fila_a{
    int *vet ;
    int tam ;
    int *inicio ;
    int * fim ;
    int capacidade;

}Fila;

Fila * criar_fila(){

        Fila * fila = (Fila*)malloc(sizeof(Fila));
        if(fila != NULL) {
            fila->inicio = NULL ;
            fila->fim = NULL ;
            fila->capacidade = 100;
            fila->tam = 0;
            fila->vet = malloc(sizeof(int) * fila->capacidade);
        }else{
            printf("Nao foi Possivel Alocar Memoria");
        }
}


void inserir_fila(Fila * fila, int n){
   fila->vet[fila->tam] = n ;
   fila->tam++;

   fila->fim[fila->tam] = fila->vet[fila->tam] ;

}












