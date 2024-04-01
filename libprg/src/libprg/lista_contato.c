#include "libprg/libprg.h"

/*vou fazer um vetor de struct*/
typedef struct {
   char nome[100] ;
   char email[50] ;
   char telefone[20] ;
}Contatos;

/*Criar a lista de Contatos*/

typedef struct lista_Contato{
    int tamanho  ;
    int capacidade ;

    Contatos * contatos ;
}lista_Contato_t ;


lista_Contato_t * lista_Contato_t() {
    lista_contato_t *listacontato = (lista_Contato_t*) malloc(sizeof(lista_Contato_t));
    listacontato->tamanho = 0;
    listacontato->capacidade = 10;
    listacontato->contatos = (Contatos*) malloc(sizeof(Contatos) * listacontato->capacidade);

    return listacontato;
}

void ler_contato(Contatos *c){
    printf("Entre com o nome: ");
    fgets(c->nome,100,stdin);
    printf("Entre com o email: ");
    fgets(c->email,50,stdin);
    printf("Entre com o numero: ");
    fgets(c->telefone,15,stdin);

}

void inserir_contato_lista(Lista_Contato * lista , Contatos  c ){
     lista->contatos[lista->tamanho++] = c ;
}








