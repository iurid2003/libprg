#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no_l{
    int dado ;
    struct no_l * proximo ;


}No_l;

//Inserir
void inserir_na_lista(No_l ** inicio, int dado ){
    No_l  * novo =(No_l*)malloc(sizeof (No_l));
    novo->dado = dado ;
    novo->proximo = novo ;
    *inicio = novo;

}


//Remover
bool remover_lista_encadeada(No_l** lista, int num) {
    No_l* atual = *lista;
    No_l* anterior = NULL;

    while (atual) {
        if (atual->dado == num) {
            if (anterior == NULL) {
                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}

//Buscar

No_l * buscar_lista_encadeada(No_l * lista , int num){
    No_l  * atual = lista ;

    while (lista){
        if(num == atual->dado){
            printf("Existe Esse elemento");
            return atual;
        }else{
            atual = atual->proximo ;
        }
    }
    printf("Esse elemento nao existe na lista");
    return  NULL ;
}


// Ordenar

void inserir_ordenada_lista(No_l ** inicio, int num){
     No_l  * novo , *aux= malloc(sizeof(No_l));
     if(novo){
         novo->dado = num ;
         if(*inicio == NULL){
             novo->proximo = NULL;
             *inicio = novo ;
         }else if (novo->dado < (*inicio)->dado){
             novo->proximo = *inicio ;
             *inicio = novo ;
         }else{
             aux = *inicio ;
             while (aux->proximo && novo->dado > aux->proximo->dado){
                 aux = aux->proximo;
                 novo->proximo = aux->proximo ;
                 aux->proximo = novo ;
             }
         }

     }
}




