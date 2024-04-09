#include "libprg/libprg.h"

/* Definição da estrutura de Contatos */



/* Função para criar uma lista de Contatos */
lista_c *lista_a() {
    lista_c *lista = (lista_c *) malloc(sizeof(lista_c));
    lista->tamanho = 0;
    lista->capacidade = 50;
    lista->contatos = (Contatos_c *) malloc(sizeof(Contatos_c) * lista->capacidade);
    return lista;
}

/*Certo */
/* Função para inserir um contato na lista */
int inserir_contato_lista(lista_c* lista , Contatos_c c) {
    lista->contatos[lista->tamanho++] = c;
    return  1 ;
}

/*buscar contato especifico */
int buscar_contato(lista_c * lista , char * nome ){
    for(int i = 0 ; i < lista->tamanho; i++ ){
        if(strcmp(lista->contatos[i].nome,nome) == 0 ){
            return i ;  /*retornando a posicao na lista */
        }
    }
    return  -1 ;
}

/* Função para imprimir todos os contatos */
void imprimir_contatos(lista_c *lista) {
    printf("--LISTA DE CONTATOS--\n");
    for (int i = 0; i < lista->tamanho; ++i) {
        printf("---CONTATO---\n");
        printf("Posicao %d\n",i + 1);
        printf(" Nome : %s ", lista->contatos[i].nome);
        printf("Email : %s ", lista->contatos[i].email);
        printf("Telefone : %s ", lista->contatos[i].telefone);
        printf("\n");
    }
}
/*Adptado*/
int editar_contato(lista_c * lista , int pos_lista,char * nome , char * email , char * telefone ){
    if(pos_lista >=  0 && pos_lista < lista->tamanho ){
    strcpy(lista->contatos[pos_lista].nome,nome);
    strcpy(lista->contatos[pos_lista].telefone,telefone);
    strcpy(lista->contatos[pos_lista].email,email);
        return 1 ;
    }else
    {
        return  0 ;
    }
}
/*Certo*/
int deletar_contato(lista_c * lista, int indice) {
    if (indice < 0 || indice >= lista->tamanho) {
        return 0;
    }

    for (int i = indice; i < lista->tamanho - 1; i++) {
        lista->contatos[i] = lista->contatos[i + 1];
    }
    lista->tamanho--;
    return 1;
}










