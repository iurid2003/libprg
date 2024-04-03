#include "libprg/libprg.h"



typedef  struct Pilha_a {
   int *vet;
   int tamanho ;
   int capacidade ;
   bool  vazio ;
}Pilha;


Pilha* Criar_Pilha(){
      Pilha * P =(Pilha *) malloc(sizeof(Pilha) );
      P->capacidade = 10 ;
      P->tamanho = 0  ;
      P->vet = (int*) malloc(sizeof(int) * P->capacidade) ;
      return P ;
}

void push(Pilha p ){

}

void pop(Pilha p ){

}

int  size(Pilha p ){
    return
}




