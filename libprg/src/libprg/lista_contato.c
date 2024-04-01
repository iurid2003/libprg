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
}Lista_Contato ;


Lista_Contato *criar_lista_contato() {
    Lista_contato *listacontato = (Lista_Contato*) malloc(sizeof(Lista_Contato));
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








