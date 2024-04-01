//
// Created by aluno on 04/03/24.
//
#include "libprg/libprg.h"
typedef struct lista_a {
    int tamanho  ;
    int *vetor ;
    int capacidade ;
    bool ordenada ;
} lista_a ;

lista_a* criar_lista(){

    lista_a* lista =(lista_a*) malloc(sizeof(lista) );
    lista->capacidade = 10 ;
    lista->tamanho = 0  ;
    lista->ordenada  = false ;
    lista->vetor = (int*) malloc(sizeof(int) * lista->capacidade) ;
   return lista ;
};


//int * inserir_num(lista_a lista,int n){
//    lista.vetor[lista.tamanho++] = n ;
//}






