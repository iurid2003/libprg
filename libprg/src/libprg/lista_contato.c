#include "libprg/libprg.h"

/*vou fazer um vetor de struct*/
typedef struct Contatos {
   char nome[100] ;
   char email[50] ;
   char telefone[20] ;
}Contatos_c;

/*Criar a lista de Contatos*/

typedef struct lista_Contato{
    int tamanho  ;
    int capacidade ;

    Contatos_c * contatos ;
}Lista_c;


Lista_c* lista_a() {
     Lista_c *lista =(Lista_c *) malloc(sizeof(Lista_c ));
     lista->tamanho= 0;
     lista->capacidade = 10;
     lista->contatos = (Contatos_c*) malloc(sizeof(Contatos_c) * lista->capacidade);

    return lista;
}

void ler_contato(Contatos_c * c){
    printf("Entre com o nome: ");
    fgets(c->nome,100,stdin);
    printf("Entre com o email: ");
    fgets(c->email,50,stdin);
    printf("Entre com o numero: ");
    fgets(c->telefone,15,stdin);

}

void inserir_contato_lista(Lista_c * lista , Contatos_c c ){
     lista->contatos[lista->tamanho++] = c ;

}

void imprimir_contato(Lista_c * lista , Contatos_c c){

    printf("Nome : %s \n",c.nome);
    printf("Email : %s \n",c.email);
    printf("Telefone : %s \n",c.telefone);

}









