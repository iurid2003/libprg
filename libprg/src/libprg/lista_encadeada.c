#include "libprg/libprg.h"


typedef struct proximo  {
  int n ;
}proximo_t;

typedef struct no{
    int dado;
    struct no * proximo_t ;
    int anterior ;
} no_t;


// adiciona normalmente
void adicionar(no_t ** inicio, int dado){
    no_t * novo = (no_t*) malloc(sizeof(no_t));
    novo->dado = dado ;
    novo->proximo_t = *inicio ;
    *inicio = novo ;
}

// adiciona ordenado
void ordenar_no(no_t ** inicio , int dado){
    no_t  * aux ,* novo = (no_t*) malloc(sizeof(no_t));
    if(novo){
        novo->dado = dado;
        if(*inicio == NULL){
          novo->proximo_t = NULL ;
        }else if (novo->dado < (*inicio)->dado){
            novo->proximo_t = *inicio  ;
            *inicio = novo;
        }else{
            aux = *inicio ;
            while(aux->proximo_t && novo->dado > aux->proximo_t->dado){
                aux = aux->proximo_t ;
                novo->proximo_t = aux->proximo_t ;
                aux->proximo_t = novo ;
            }

        }
    }else{
        printf("Erro ao alocar!");
    }
}

// na hora de adicionar tenho que buscar

 no_t* buscar_n(no_t ** inicio , int dado ){

    no_t  * aux , *no = NULL ;
    aux = * inicio ;
    while(aux && aux->proximo_t != dado) {
        aux = aux->proximo_t ;
    }
    if(aux){
        no= aux ;
    }

    return no  ;
}

/*Remover no*/
bool remover(no_t** inicio, int dado){
no_t* atual = *inicio;
no_t* anterior = NULL;
while(atual != NULL){
if (atual->dado == dado){
if (anterior == NULL) {
*inicio = atual->proximo_t;
} else {
anterior->proximo_t = atual->proximo_t;
}
free(atual);
return true;
}
anterior = atual;
atual = atual->proximo_t;
}
return false;
}
// detruir nos
void destruir(no_t** inicio){
no_t* atual = *inicio;
no_t* prox;
while(atual != NULL){
prox = atual->proximo_t;
free(atual);
atual = prox;
}
*inicio = NULL;
}

/*Get retornando elementos */
/*No main eu imprimo os elementos*/



