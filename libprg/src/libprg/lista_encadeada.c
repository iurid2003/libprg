#include "libprg/libprg.h"


typedef struct no{
    int dado;
    struct no * proximo_t ;
} no_t;

typedef  struct lista_a{
     no_t * inicio ;
     int tam ;
}Lista;

//Cria lista de nos
void criar_lista(Lista * lista){
    lista->inicio = NULL ;
    lista->tam = 0 ;
}

//adiciona normalmente no  no_t
void adicionar_no(no_t** inicio, int dado){
no_t * novo = (no_t*) malloc(sizeof (no_t));
novo->dado = dado;
novo->proximo_t = *inicio;
*inicio= novo;


// adiciona normalmente na lista
void adiciona_lista(Lista * lista, int dado){
    no_t * novo = malloc(sizeof(no_t));
    novo->dado = dado ;
    novo->proximo_t = lista->inicio  ;
    lista->inicio = novo ;
    lista->tam++;
}

// adiciona ordenado no No_t
void ordena_no(no_t ** lista ,int dado){
    no_t * aux ,  * novo = malloc(sizeof (no_t));
    if(novo){
        novo->dado = dado ;
        if(*lista = NULL){
            novo->proximo_t = NULL;
            *lista = novo ;

        }else if(novo->dado < (*lista)->dado){
            novo->proximo_t = *lista ;
            *lista = novo ;
        }else{
            aux = *lista ;
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


// Ordenada na lista
void


// na hora de adicionar tenho que buscar

 no_t* buscar_n(no_t * inicio , int dado ){

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
 bool remover(no_t ** inicio, int dado){
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

void destruir(no_t ** inicio){
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



