
#include "libprg/libprg.h"

 typedef struct fila{
    int tamanho;
    int inicio ;
    int *vetor ;
    int capacidade ;
    bool vazia;

}fila_a;
fila_a * cria_fila(int capacidade) {
    fila_a* fila = (fila_a*) malloc(sizeof(capacidade));
    fila->tamanho = 0 ;
    fila->vazia = true ;
    fila->inicio = 0 ;
    fila->capacidade = capacidade ;



}
void enfilerar(fila_a * fila, int n ){
    fila->vetor[fila->tamanho] = n ;
    int n_ant = n ;
    if(fila->vetor[fila->tamanho]){
        fila->vetor[fila->tamanho - 1] = n ;
    }
  }

int getinicio(fila_a * fila){
    return fila->vetor[0] ;
}
int getfinal(fila_a *  fila){
    return fila->vetor[fila->tamanho] ;
}
int gettamamho(fila_a * fila){
    return  fila->tamanho ;
}


bool isvazia(fila_a * fila){}

bool ischeia(fila_a * fila){}
















