//
// Created by aluno on 04/03/24.
//
#include "libprg/libprg.h"
typedef struct lista {
    int tamanho  ;
    int *vetor ;
    int capacidade ;
    bool ordenada ;
} lista_a ;

void ciar_lista(){

    lista_a* lista =(lista_a*) malloc(sizeof(lista) );
    lista->capacidade = 10 ;
    lista->tamanho = 0  ;
    lista->ordenada  = false ;
    lista->vetor = (int*) malloc(sizeof(int) * lista->capacidade) ;

};

int busca_linear(lista_a lista ,int alvo){
    int i = 0 ;
    for (i ; i < lista.tamanho ; i++){
        if(lista.vetor[i] == alvo){
            return 1 ;
        }
    }
    return  0 ;
}
bool buscaLinearOrdenada(lista_a lista ,int alvo) {
    int i = 0;

    while (i < lista.tamanho && lista.vetor < alvo) {
        i++;
    }

    // Se o elemento foi encontrado, retorna verdadeiro
    if (i < lista.tamanho && lista.vetor == alvo) {
        return true;
    } else {
        return false; // Elemento não encontrado
    }
}

int busca_binaria(lista_a lista ,int tamanho, int alvo){
    int i = 1 ;
    int j = tamanho ;
    int meio = 0;
    while (i <= j){
        meio = i + (j - i)/2;
        if(lista.vetor[meio] == alvo){
            return 1 ;
        }else if(lista.vetor[meio] < alvo){
            i = meio + 1 ;
        }else{
            j = meio - 1 ;
        }
    }
    return 0 ;
}

int recursivo_bin(int *vet ,int i , int f ,int alvo){
  int meio ;
    if(i < f){
        meio = i + (f - i)/2;
        if(vet[meio] == alvo){
         return 1 ;
        }
        if(vet[meio] > alvo){
           return recursivo_bin(vet,i,meio - 1,alvo);
        }
        return recursivo_bin(vet,meio + 1,f,alvo);
    }
    return  0 ;
}

int* inserir_num(int *vet , int tamanho , int num ){
    vet = malloc(sizeof(int) * (tamanho + 1));
    vet[tamanho++] = num ;

    //talvez eu volte ordenado ;

    return vet ;

};

int* remove_vet(int *vet , int tamanho , int alvo){



    return  vet ;
}






