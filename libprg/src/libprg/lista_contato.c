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
    lista->capacidade = 50;
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


    printf("Contato lido\n");
    // vou colocar pra voltar pro menu principal ;
}

/* Função para inserir um contato na lista */
void inserir_contato_lista(lista_c* lista , Contatos_c c) {
    lista->contatos[lista->tamanho++] = c;
}

/*buscar contato especifico */
int buscar_contato(lista_c * lista , char * nome){
    for(int i = 0 ; i < lista->tamanho; i++ ){
        if(strcmp(lista->contatos[i].nome,nome) == 0 ){
            printf("----Contato Encotrado----\n");
            printf(" Nome : %s ", lista->contatos[i].nome);
            printf("Email : %s ", lista->contatos[i].email);
            printf("Telefone : %s ", lista->contatos[i].telefone);
            printf("\n");
            return i ;  /*retornando a posicao na lista */

        }
    }
    printf("Esse nome não foi encontrado.\n");
    return  -1 ;
}

/* Função para imprimir todos os contatos */
void imprimir_contatos(lista_c *lista) {
    getchar();
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

void editar_contato(lista_c * lista , int pos_lista ){
    getchar();
    int op = 0 ;
    char novo_nome[100];
    char novo_email[50];
    char novo_tele[20];
    printf("---EDITE---\n");
    printf(" Nome : ");
    fgets(novo_nome,100,stdin);
    printf("Email : ");
    fgets(novo_email,50,stdin);
    printf("telefone : ");
    fgets(novo_tele,20,stdin);

    strcpy(lista->contatos[pos_lista].nome,novo_nome);
    strcpy(lista->contatos[pos_lista].telefone,novo_tele);
    strcpy(lista->contatos[pos_lista].email,novo_email);
    printf("Editado Com Sucesso\n");
}

int deletar_contato(lista_c * lista , int indice){
    int i = indice ;
    if(indice < 0 || indice > lista->tamanho){
        return 0   ;
    }
    for (i; i < lista->tamanho -1 ; i++) {
        lista->contatos[i] = lista->contatos[i + 1];
    }
    lista->tamanho--;
    return 1 ;
}

void menu(lista_c * Contatos){
    printf("----------------------------------------------------------------\n");
    printf("----------------------------------------------------------------\n");
    printf("----------------------------------------------------------------\n");

    int p = 0 ;
    char nome[100] ;
    /*Passando localamente a estrutura contatos*/
    Contatos_c  novo_contato ;
    int indice_busca = -1 ;
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
            /*Ponteiro para um unico contato*/
            case 1 : ler_contato(&novo_contato);
                inserir_contato_lista(Contatos,novo_contato) ; break ;
            case 2 : imprimir_contatos(Contatos);break ;
            case 3 :
                getchar();
                printf("Entre com o nome : ");
                fgets(nome,100,stdin);
               indice_busca = buscar_contato(Contatos,nome);
               if(indice_busca != -1){
                   int op = 0 ;
                   printf("Entre com uma opcao \n");
                   printf(" 1 para editar ou 2 para deletar \n");
                   scanf("%d",&op);

                   switch (op) {
                       case 1 :
                           editar_contato(Contatos,indice_busca); break ;
                       case 2 :
                             deletar_contato(Contatos, indice_busca);
                           if(deletar_contato(Contatos,indice_busca == 1)){
                               printf("Deletado com Sucesso");
                           }else{
                               printf("Erro ao Deletar");
                           }
                           break;
                       default:
                           printf("Opcao invalida\n");
                   }
               }
                break ;
            case 4 : printf("Saindo");
                return ;
            default:
                printf("Opcao inexistente\n");
        }
    }
}











