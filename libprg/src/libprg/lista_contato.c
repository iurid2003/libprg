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
}ListaContato ;


ListaContato * listacontato() {
    ListaContato *listacontato =(ListaContato *) malloc(sizeof(ListaContato));
     listacontato->tamanho= 0;
     listacontato->capacidade = 10;
     listacontato->contatos = (Contatos*) malloc(sizeof(Contatos) * listacontato->capacidade);

    return listacontato;
}

void ler_contato(Contatos * c){
    printf("Entre com o nome: ");
    fgets(c->nome,100,stdin);
    printf("Entre com o email: ");
    fgets(c->email,50,stdin);
    printf("Entre com o numero: ");
    fgets(c->telefone,15,stdin);

}

void inserir_contato_lista(ListaContato * lista , Contatos c ){
     lista->contatos[lista->tamanho++] = c ;
}








