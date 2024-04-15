#include "libprg/libprg.h"


typedef struct proximo  {
  int n ;
}proximo_t;

typedef struct no{
    int dado;
    struct no * proximo_t ;
    int anterior ;
} no_t;

void adicionar(no_t ** inicio, int dado){
    no_t * novo = (no_t*) malloc(sizeof(no_t));
    novo->dado = dado ;
    novo->proximo_t = *inicio ;
    *inicio = novo ;
}

// na hora de adicionar tenho

//no_t* buscar_n(no_t * inicio , int dado ){
//    inicio->anterior = inicio->dado ;
//    if(inicio->anterior == NULL){
//        printf("no vazio");
//    } else{
//        inicio->dado  = dado ;
//        return  ;
//    }
//}

//bool remover(no_t** inicio, int dado){
//no_t* atual = *inicio;
//no_t* anterior = NULL;
//while(atual != NULL){
//if (atual->dado == dado){
//if (anterior == NULL) {
//*inicio = atual->proximo_t;
//} else {
//anterior->proximo_t = atual->proximo_t;
//}
//free(atual);
//return true;
//}
//anterior = atual;
//atual = atual->proximo_t;
//}
//return false;
//}
//
//
//void destruir(no_t** inicio){
//no_t* atual = *inicio;
//no_t* prox;
//while(atual != NULL){
//prox = atual->proximo_t;
//free(atual);
//atual = prox;
//}
//*inicio = NULL;
//}




