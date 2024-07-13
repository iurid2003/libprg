#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct lista_l {
    int tamanho ;
    int capacidade;
    int *vetor ;
    bool vazio ;



}lista_linear;


lista_linear * criar_lista(){
    lista_linear * lista = (lista_linear *)malloc(sizeof (lista_linear)) ;
    lista->tamanho = 0 ;
    lista->capacidade = 100;
    lista->vazio = false ;
    lista->vetor ;
}

void inserir(lista_linear*listaLinear , int n ){
    if(listaLinear == NULL){
        printf("Nao foi possivel colocar o numero");
    }else {
        listaLinear->vetor[listaLinear->tamanho] = n;
        listaLinear->tamanho++;
    }
}

int retirar(lista_linear*listaLinear, int n){
    for (int i = 0; i < listaLinear->tamanho; ++i) {
        if (listaLinear->vetor[i] == n) {
            listaLinear->vetor[i] == listaLinear->vetor[listaLinear->tamanho-1];
            listaLinear->tamanho--;
            return 1 ;
        }
    }
    return 0 ;
}

/*Buscar linear*/
/*lista Desordenada*/

int buscar(lista_linear*listaLinear ,int n){
    for (int i = 0; i < listaLinear->tamanho; ++i) {
        if(listaLinear->vetor[i] == n){
            return 1;
        }
    }
    return 0 ;
}

/*Busca binaria*/
// Ordenada

int busca_binaria_it(lista_linear*listaLinear, int n){
    int inicio = 1 ;
    int fim = listaLinear->tamanho ;
    int meio ;

    while (inicio <= fim){
        if(listaLinear->vetor[meio] == n){
            return 1 ;
        }else if(listaLinear->vetor[meio] < n){
            inicio = meio + 1 ;
        }else{
            fim = meio - 1 ;
        }
    }
    return 0 ;
}





int main(void){

}














