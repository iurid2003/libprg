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
    lista->vetor = malloc(sizeof(lista_linear)*lista->capacidade) ;
}

void inserir(lista_linear*listaLinear , int n ){
    if(listaLinear == NULL){
        printf("Nao foi possivel colocar o numero");
    }else {
        listaLinear->vetor[listaLinear->tamanho++] = n ;
    }
}

int retirar(lista_linear*listaLinear, int n){
    for (int i = 0; i < listaLinear->tamanho; ++i) {
        if (listaLinear->vetor[i] == n) {
            listaLinear->vetor[i] == listaLinear->vetor[listaLinear->tamanho - 1];
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
    int inicio = 0;
    int fim = listaLinear->tamanho - 1 ;
    int meio ;

    while (inicio <= fim){
        meio = inicio + (fim - inicio)/2;
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

//Busca_Binaria_rec

int busca_binaria_rec(lista_linear*listaLinear,int inicio , int fim , int num){
     inicio = 1;
     fim  = listaLinear->tamanho ;
    int  meio  ;
    if(inicio <= fim){
     meio = inicio + (fim - inicio)/2;
     if(listaLinear->vetor[meio] = num){
         return  1;
     }
     if(listaLinear->vetor[meio] > num){
         return busca_binaria_it(listaLinear,num);
     }

        return busca_binaria_it(listaLinear,num);
    }
}

void imprimir(lista_linear*listaLinear){
    for (int i = 0; i < listaLinear->tamanho; ++i) {
        printf("%d ",listaLinear->vetor[i]);
    }printf("\n");
}

int main(void){
       lista_linear * l = criar_lista();

    inserir(l,10);
    inserir(l,11);
    imprimir(l);

   int i = busca_binaria_rec(l,1,l->tamanho,10);
   printf("%d",i);

    free(l->vetor);
    free(l);


}














