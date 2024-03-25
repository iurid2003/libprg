
#include "libprg/libprg.h"

 typedef struct fila{
    int tamanho;
    int inicio ;
    int *vetor ;
    bool vazia;

}fila_a;
fila_a * cria_fila() {
    fila_a* fila = (fila_a*) malloc(sizeof(fila));
    fila->tamanho = 0 ;
    fila->vazia = true ;
    fila->inicio = 0 ;


}
void enfilerar(fila_a fila, int n ){
    /*Adiciona um elemento no final da fila*/
    fila.vetor[fila.inicio + 1] = n  ;

}




