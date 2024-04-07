#include "libprg/libprg.h"

/* Definição da estrutura de Contatos */


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
/*Tenho que fazer voltar */
void ler_contato(Contatos_c * c) {
    getchar();
    printf("---CONTATO---\n");
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
    for(int i = 0 ; i < lista->tamanho; i++ ){
        if(strcmp(lista->contatos[i].nome,nome) == 0 ){
            printf("Nome : %s \n", lista->contatos[i].nome);
            printf("Email : %s \n", lista->contatos[i].email);
            printf("Telefone : %s \n", lista->contatos[i].telefone);

            return ;
        }
    }
    printf("Esse nome não foi encontrado.\n");
}

/* Função para imprimir todos os contatos */
void imprimir_contatos(lista_c *lista) {
    getchar();
    printf("--LISTA DE CONTATOS--\n");
    for (int i = 0; i < lista->tamanho; ++i) {
        printf("---CONTATO---\n");
        printf("Posicao %d\n",lista->tamanho);
        printf(" Nome : %s ", lista->contatos[i].nome);
        printf("Email : %s ", lista->contatos[i].email);
        printf("Telefone : %s ", lista->contatos[i].telefone);
        printf("\n");
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

void menu(lista_c * Contatos){
    int p = 0 ;
    char nome[100] ;

    while (p != 5){
        printf("---CONTATOS---\n");
        printf("ESCOLHA UMA FUNCAO\n");
        printf("novo contato : 1 \n");
        printf("Imprimir contatos: 2\n");
        printf("buscar contato : 3\n");
        printf("Sair: 4\n");

        printf("Escolha : ");
        scanf("%d",&p);
        printf("\n");

        switch (p) {
            case 1 : ler_contato(&Contatos[Contatos->tamanho]);
                    Contatos->tamanho++ ; break ;
            case 2 : imprimir_contatos(Contatos);break ;
            case 3 :
                getchar();
                printf("Entre com o nome : ");
                fgets(nome,100,stdin);
                buscar_contato(Contatos,nome);
                break ;
            case 4 : printf("Saindo"); break ;
            default:
                printf("Opcao inexistente\n");
        }
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










