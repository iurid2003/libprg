#include "libprg/libprg.h"

typedef struct no{
    int dado;
    struct no * proximo_t ;
} no_t;


//adiciona normalmente no  no_t
void adicionar_no(no_t ** inicio, int dado) {
    no_t * novo = malloc(sizeof(no_t));
    novo->dado = dado;
    novo->proximo_t = *inicio;
    *inicio = novo;
}
// adiciona ordenado no No_t

void ordena_no(no_t ** lista ,int dado){
    no_t *aux ,  * novo = malloc(sizeof (no_t ));
    novo->dado = dado ;
    if(*lista == NULL){
        novo->proximo_t = NULL  ;
        *lista = novo ;
    }else if(novo->dado < (*lista)->dado){
        novo->proximo_t = *lista ;
        *lista = novo ;

    }else{
        aux = *lista ;
        while(aux->proximo_t && novo->dado > aux->proximo_t->dado){
            aux = aux->proximo_t ;
            novo->proximo_t = aux->proximo_t ;
            aux->proximo_t = novo ;        }
    }
}

//remove no_t

no_t  * remove_no(no_t ** inicio , int dado){
    no_t   * aux,  * remover = NULL ;
     if(*inicio){
         if((*inicio)->dado == dado){
             remover = *inicio;
             *inicio = remover->proximo_t ;
         }
         else{
             aux = *inicio ;
             while(aux->proximo_t && aux->proximo_t->dado != NULL){
                 aux = aux->proximo_t ;
                 if(aux->proximo_t){
                     remover = aux->proximo_t ;
                     aux->proximo_t = remover->proximo_t ;
                 }
             }
         }
     }

    return  remover ;
}
// destruir nos ;
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

// Busca NO no

no_t  * buscar(no_t ** inicio , int dado){
    no_t  * aux , *no = NULL ;
    while (aux && aux->proximo_t !=  NULL){
        aux = aux->proximo_t ;
    }
    if(aux)
        no = aux ;
    return  no ;
}


//lista
typedef  struct lista_a{
    no_t * inicio ;
    int tam ;
}Lista;

//Cria Lista
void criar_lista(Lista * lista){
    lista->inicio = NULL ;
    lista->tam = 0 ;
}
// adiciona normalmente na lista
void adiciona_lista(Lista * lista, int dado){
    no_t * novo = malloc(sizeof(no_t));
    novo->dado = dado ;
    novo->proximo_t = lista->inicio  ;
    lista->inicio = novo ;
    lista->tam++;
}

// Ordenada na lista
void inserir_ordenado_lista(Lista * lista , int dado){
    no_t  * aux , * novo = malloc(sizeof (no_t));
    novo->dado = dado ;
    if(lista->inicio = NULL){
        novo->proximo_t = NULL;
        lista->inicio = novo ;
    }else if(novo->dado < lista->inicio->dado){
        novo->proximo_t = lista->inicio ;
        lista->inicio = novo ;
    }else{
        aux = lista->inicio ;
        while(aux->proximo_t && novo->dado > aux->proximo_t->dado){
            aux = aux->proximo_t ;
            novo->proximo_t = aux->proximo_t ;
            aux->proximo_t = novo ;
        }
    }
    lista->tam++;
}

//Remover da lista
no_t  * remover(Lista * lista , int dado){
    no_t *aux, * remover = NULL ;

    if(lista->inicio){
        if(lista->inicio->dado = dado){
            remover = lista->inicio ;
            lista->inicio = remover->proximo_t ;
            lista->tam-- ;
        }else{
            while (aux->proximo_t && aux->proximo_t->dado != NULL){
                        aux = aux->proximo_t ;
                        if(aux->proximo_t){
                            remover = aux->proximo_t ;
                            aux->proximo_t = remover->proximo_t ;
                            lista->tam--;
                        }

            }
        }
    }

    return  remover ;
}

// busca

no_t * buscar_lista(Lista * lista , int dado){
    no_t * aux ,*no = NULL ;
    aux = lista->inicio;
    while (aux != NULL && aux->proximo_t != dado)
        aux = aux->proximo_t;
    if(aux)
        no = aux ;
     return  no ;

}










/*Get retornando elementos */
/*No main eu imprimo os elementos*/



