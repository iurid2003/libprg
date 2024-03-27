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

int criar_lista(){

    lista* lista =(lista_a*) malloc(sizeof(lista) );
    lista->capacidade = 10 ;
    lista->tamanho = 0  ;
    lista->ordenada  = false ;
    lista->vetor = (int*) malloc(sizeof(int) * lista->capacidade) ;

};

int busca_linear(lista lista ,int alvo){
    int i = 0 ;
    for (i ; i < lista.tamanho ; i++){
        if(lista.vetor[i] == alvo){
            return 1 ;
        }
    }
    return  0 ;
}

int busca_binaria(lista_a  lista ,int tamanho, int alvo){
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

int binario_recursivo(lista_a lista, int i, int f, int alvo) {
    int meio;

    if (i <= f) {
        meio = i + (f - i) / 2;
        if (lista.vetor[meio] == alvo) {
            return 1; // Elemento encontrado
        }
        if (lista.vetor[meio] > alvo) {
            return binario_recursivo(lista, i, meio - 1, alvo); // Busca na metade esquerda
        }
        return binario_recursivo(lista, meio + 1, f, alvo); // Busca na metade direita
    }
    return 0; // Elemento não encontrado
}
int* inserir_numero(lista_a lista ,int num ){
    lista.vetor = malloc(sizeof(int) * (lista.tamanho + 1));
    lista.vetor[lista.tamanho++] = num ;

    //talvez eu volte ordenado ;

    return lista.vetor ;

}

void removeNumero(lista_a lista, int num) {
    int i, j;

    for (i = 0; i < lista.tamanho; i++) {
        if (lista.vetor[i] == num) {

            for (j = i; j < lista.tamanho - 1; j++) {
                lista.vetor[j] = lista.vetor[j + 1];
            }

            // Decrementa o tamanho do vetor após a remoção
            (lista.tamanho)--;
            // Decrementa i para verificar novamente o mesmo índice, já que o vetor foi deslocado
            i--;
        }
    }
}





