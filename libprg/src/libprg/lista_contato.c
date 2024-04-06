#include "libprg/libprg.h"

/* Definição da estrutura de Contatos */
 typedef struct Contatos {
     char nome[100];
     char email[50];
     char telefone[20];
} Contatos_c;

/* Definição da estrutura de Lista */
typedef struct lista {
    int tamanho;
    int capacidade;
    Contatos_c *contatos;
} lista_c;

/* Função para criar uma lista de Contatos */
lista_c *lista_a() {
    lista_c *lista = (lista_c *) malloc(sizeof(lista_c));
    lista->tamanho = 0;
    lista->capacidade = 10;
    lista->contatos = (Contatos_c *) malloc(sizeof(Contatos_c) * lista->capacidade);
    return lista;
}

/* Função para ler um novo contato */
void ler_contato(Contatos_c *c) {
    printf("Entre com o nome: ");
    fgets(c->nome, 100, stdin);
    printf("Entre com o email: ");
    fgets(c->email, 50, stdin);
    printf("Entre com o numero: ");
    fgets(c->telefone, 20, stdin);

    printf("Contato lido");
    // vou colocar pra voltar pro menu principal ;
}

/* Função para inserir um contato na lista */
void inserir_contato_lista(lista_c* lista , Contatos_c c) {
    lista->contatos[lista->tamanho++] = c;
}

/*buscar contato especifico */
void buscar_contato(lista_c * lista , char * nome){
    for(int i = 0 ; i < lista->tamanho ; i++ ){
        if(strcmp(lista->contatos[i].nome, nome) == 0 ){
            printf("Nome : %s \n", lista->contatos[i].nome);
            printf("Email : %s \n", lista->contatos[i].email);
            printf("Telefone : %s \n", lista->contatos[i].telefone);

            return ;
        }
    }
    printf("Esse nome não foi encontrado.");
}

/* Função para imprimir todos os contatos */
void imprimir_contatos(lista_c *lista) {
    for (int i = 0; i < lista->tamanho; ++i) {
        printf("Nome : %s \n", lista->contatos[i].nome);
        printf("Email : %s \n", lista->contatos[i].email);
        printf("Telefone : %s \n", lista->contatos[i].telefone);
    }
}

void deletar_contato(lista_c * lista, int indice, char *nome){
    lista[indice]  ;
}

/*Quando eu deletar um contato da lista terei colocor os contatos de novo em ordem*/
void realocar_lista(lista_c * lista){
    int i = 0 ;
   while(i < lista->tamanho - 1){

   }

}



//int main() {
//    lista_c *minha_lista = lista_a();
//    Contatos_c novo_contato;
//
//    ler_contato(&novo_contato);
//    inserir_contato_lista(minha_lista, novo_contato);
//    imprimir_contato(minha_lista);
//
//    // Lembrando de liberar a memória alocada
//    free(minha_lista->contatos);
//    free(minha_lista);
//
//    return 0;
//}










