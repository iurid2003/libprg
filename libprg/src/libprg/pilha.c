#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef  struct Pilha_a {
    int *vet;
    int tamanho ;
    int capacidade ;
    bool  vazio ;
}Pilha;

Pilha* Criar_Pilha(){
      Pilha * P =(Pilha *) malloc(sizeof(Pilha));
      P->capacidade = 10 ;
      P->tamanho = 0  ;
      P->vet = (int*) malloc(sizeof(int) * P->capacidade) ;

}
/*Adicionar*/
void push(Pilha *p , int n){
   if(p == NULL){
       printf("Pilha Cheia ou Nao foi possivel alocar");
   } else{
         p->vet[p->tamanho++] = n ;

   }
}

void pop(Pilha *p){
   if(p->tamanho > 0){
        p->tamanho--;
    }else{
        printf("A Pilha esta vazia");
    }

}
void imprimir_pilha(Pilha *p){
    for (int i = 0; i < p->tamanho; ++i) {
        printf("%d ",p->vet[i]);
    }
}

int size(Pilha *p ){
    return p->tamanho ;
}

void empty(Pilha *p){

    if(p->vet[0] == NULL){
        printf("Vazia");
    }else{
        printf("Tem elementos");
    }printf("\n");

}

int main(void){
    Pilha *p = Criar_Pilha();
    empty(p);


    push(p,10);
    push(p,12);
    empty(p);

    imprimir_pilha(p);
    pop(p);
    printf("\n");
    imprimir_pilha(p);
    int i = size(p);
    printf("\n%d",i);
    push(p,113);
    printf("\n");
    imprimir_pilha(p);
    printf("\n");
     i = size(p);
    printf("%d",i);


}


