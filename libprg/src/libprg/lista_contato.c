#include "libprg/libprg.h"

/*vou fazer um vetor de struct*/
typedef struct {
   char nome[100] ;
   char email[50] ;
   char telefone[20] ;
}Contatos;

/*Criar a lista de Contatos*/

typedef struct lista_contato{
    int tamanho  ;
    int capacidade ;

    /*vetor de struct*/
    //tenho que ler e armazenar na minha lista o struct
    int *v ;
    Contatos * contatos ;
}Lista_contato ;


Lista_contato * contato (){
    Lista_contato * contato =   ;
   contato->tamanho = 0 ;
   contato->capacidade = 10 ;


}

/*Tenho qur armazenar na lista essa struct na pos 1 */
void ler_contato(Contatos c){
    printf("Entre com o nome");
    fgets(c.nome,100,stdin);
    printf("Entre com o telefone");
    fgets(c.telefone,20,stdin);
    printf("Entre com email");
    fgets(c.email,20,stdin);
}

/*Essa linha imprime um contato */
//tenho que fazer isso dentro da lista ;
void imprimir_contatos(Contatos c, int i ){
    printf("--Contato %d--",i);
    printf("Nome: %s",c.nome);
    printf("Email: %s",c.email);
    printf("");

}









