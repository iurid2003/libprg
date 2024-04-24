#include "libprg/libprg.h"

typedef struct no{
    int dado;
    struct no * proximo_t ;
    struct no * anterior_t ;
} no_t;


/*Lista dupalmente encadeada*/

//adiciona normalmente no  no_t
void adicionar_no(no_t ** inicio, int dado) {
    no_t * novo = malloc(sizeof(no_t));

    if(novo) {
        novo->dado = dado;
        novo->proximo_t = *inicio;
        novo->anterior_t = NULL;
        *inicio = novo;
        if(*inicio){
            (*inicio)->anterior_t = novo ;
            *inicio = novo ;
        }

    }
}
// adiciona ordenado no No_t

void ordena_no(no_t ** lista ,int dado) {
    no_t *aux, *novo = malloc(sizeof(no_t));
    if (novo) {
        novo->dado = dado;

        if (*lista == NULL) {
            novo->proximo_t = NULL;
            novo->anterior_t =NULL ;
            *lista = novo;
        } else if (novo->dado < (*lista)->dado) {
            novo->proximo_t = *lista;
            (*lista)->anterior_t = novo ;
            *lista = novo;

        } else {
            aux = *lista;
            while (aux->proximo_t && novo->dado > aux->proximo_t->dado) {
                aux = aux->proximo_t;
                aux->proximo_t = novo ;
                novo->proximo_t = aux->proximo_t;
                aux->proximo_t->anterior_t = novo ;
                novo->anterior_t = aux ;
                aux->proximo_t = novo;
            }
        }
    }
}
//remove no_t

no_t  * remove_no(no_t ** inicio , int dado){
    no_t   * aux,  * remover = NULL ;
     if(*inicio){
         if((*inicio)->dado == dado){
             remover = *inicio;
             *inicio = remover->proximo_t ;
             if(*inicio)
                 (*inicio)->anterior_t  = NULL ;
         }
         else{
             aux = *inicio ;
             while(aux->proximo_t && aux->proximo_t->dado != NULL){
                 aux = aux->proximo_t ;
                 if(aux->proximo_t){
                     remover = aux->proximo_t ;
                     aux->proximo_t = remover->proximo_t ;
                     if(aux->proximo_t)
                         aux->proximo_t->anterior_t = aux ;
                 }
             }
         }
     }

    return  remover ;
}
// destruir nos ;8
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


// tenho que colocar os elementos em um vetor




//lista circular_encadeada
typedef  struct lista_a{
    no_t * inicio ;
    no_t * fim ;
    int tam ;
    bool ordenado ;
}Lista;

//Cria Lista
Lista * criar_lista(bool ordenado){
    Lista * lista = malloc(sizeof (Lista));
    if(lista) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tam = 0;
        lista->ordenado = ordenado ;
        return  lista ;
    }else{
        return NULL;
    }
}
// adiciona normalmente na lista
void adiciona_lista(Lista * lista, int dado ){

    no_t * novo = malloc(sizeof(no_t));
    no_t  * aux = malloc(sizeof (no_t));
    aux = NULL ;
    if(novo) {
        novo->dado = dado;
        novo->proximo_t = lista->inicio;
        lista->inicio = novo;
        if (lista->fim == NULL) {
            lista->fim = novo;
            lista->fim->proximo_t = lista->inicio;
            lista->tam++;
        }
    }
}

int get_tamanho(Lista * lista){

    return lista->tam ;
}





// Ordenada na lista
void inserir_ordenado_lista(Lista * lista , int dado){
    no_t  * aux , * novo = malloc(sizeof (no_t));
    novo->dado = dado ;
    if(lista->inicio == NULL){
        adiciona_lista(lista,dado);
    }else if(novo->dado < lista->inicio->dado){
        adiciona_lista(lista,dado);
    }else{
        aux = lista->inicio ;
        while(aux->proximo_t != lista->inicio && novo->dado > aux->proximo_t->dado){
           /*fazer funcao para inserir no fim */
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
        if(lista->inicio->dado == dado){
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

// busca na lista

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
 int *get_elementos(Lista * lista){
    no_t  * aux  = NULL ;
    aux = lista->inicio ;
    int *elementos = malloc(lista->tam * sizeof (int)) ;

    for(int i = 0 ; i < lista->tam && aux != NULL ;i++){
        elementos[i] = aux->dado ;
        aux = aux->proximo_t ;
    }
    return elementos ;
}
//lista circular_duplamente_encadeada



/*No main eu imprimo os elementos*/


