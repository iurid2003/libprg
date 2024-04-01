
#include "libprg/libprg.h"

 typedef struct fila{
    int valor ;
    int tamanho ;
    int capacidade = 10 ;
    struct  fila * proximo ;
}Fila;



void enqueue(int n){
    Fila * novo  = malloc( sizeof (Fila));











