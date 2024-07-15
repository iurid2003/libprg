#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no_l{
    int dado ;
    struct no_l * proximo ;
}No_l;

typedef struct {
    No_l * inicio ;
    No_l * fim ;
    int tam ;
}Lista_Encadeada;

//Inserir

void criar_lista_encadeada(Lista_Encadeada * listaEncadeada){
    listaEncadeada->inicio = NULL ;
    listaEncadeada->fim = NULL;
    listaEncadeada->tam = 0 ;
}

void inserir_na_lista(Lista_Encadeada * inicio, int dado ){
    No_l  * novo =(No_l*)malloc(sizeof (No_l));
    if(novo) {
        novo->dado = dado;
        novo->proximo = inicio->inicio;
        inicio->inicio = novo;
        if(inicio->fim == NULL){
            inicio->fim = novo ;
            inicio->fim->proximo = inicio->inicio ;
        inicio->tam++;
    }else{
        printf("");
    }
}


//Remover
bool remover_lista_encadeada(Lista_Encadeada * listaEncadeada, int num) {
    No_l* atual = listaEncadeada->inicio;
    No_l* anterior = NULL;

    while (atual) {
        if (atual->dado == num) {
            if (anterior == NULL) {
                listaEncadeada->inicio = atual->proximo;
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

void buscar_lista_encadeada(Lista_Encadeada * lista , int num){
    No_l * atual = lista->inicio ;

    while (atual){
        if(num == atual->dado){
            printf("Existe Esse elemento\n");
            return ;
        }else{atual = atual->proximo ;}
    }
    printf("Esse elemento nao existe na lista\n");
}


// Ordenar

void inserir_ordenada_lista(Lista_Encadeada *listaEncadeada, int num){
    No_l  * novo , *aux= (No_l*) malloc(sizeof(No_l));

    if(novo){
        novo->dado = num ;
        if(listaEncadeada->inicio == NULL){
            inserir_na_lista(Lista_Encadeada,num);
        }else if(novo->dado < listaEncadeada->inicio->dado){
            novo->proximo = listaEncadeada->inicio ;
            listaEncadeada->inicio = novo ;
        }else{
            aux = listaEncadeada->inicio ;
            while(aux->proximo && novo->dado > aux->proximo->dado ){
               aux = aux->proximo ;
               novo->proximo = aux->proximo;
               aux->proximo = novo;
            }
            listaEncadeada->tam++;
        }

    }else{
        printf("Erro ao Alocar memoria");
    }

}

void imprimir(Lista_Encadeada listaEncadeada){
    No_l *no = listaEncadeada.inicio;
    printf("---lista---\n");
    while (no){
        printf("%d",no->dado);
        no = no->proximo;
    }
}




