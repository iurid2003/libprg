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

/*Certo */
/* Função para inserir um contato na lista */
void inserir_contato_lista(lista_c* lista , Contatos_c c) {
    lista->contatos[lista->tamanho++] = c;
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
/*Adptado*/
int editar_contato(lista_c * lista , int pos_lista,char * nome , char * email , char * telefone ){
    if(pos_lista >=  0 || pos_lista < lista->tamanho ){
    strcpy(lista->contatos[pos_lista].nome,nome);
    strcpy(lista->contatos[pos_lista].telefone,email);
    strcpy(lista->contatos[pos_lista].email,telefone);
        return 1 ;
    }else
    {
        return  0 ;
    }
}
/*Certo*/
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
    char nome[100];
    char email[50];
    char telefone[20];
    int p = 0 ;
    /*Passando localamente a estrutura contatos*/
    Contatos_c  novo_contato ;
    int indice_busca = -1 ;
    while (p != 5){

        printf("\n----CONTATOS----\n");
        printf("ESCOLHA UMA FUNCAO\n");
        printf("novo contato : 1 \n");
        printf("Imprimir contatos: 2\n");
        printf("buscar contato : 3\n");
        printf("Sair: 4\n");
        printf("Escolha : ");
        scanf("%d",&p);
        printf("\n");
        switch (p) {
            /*Adptar para ler aqui*/
            case 1 : printf("---CONTATO---\n");
                getchar();
                printf("Entre com o nome: ");
                fgets(novo_contato.nome, 100, stdin);
                printf("Entre com o email: ");
                fgets(novo_contato.email, 50, stdin);
                printf("Entre com o numero: ");
                fgets(novo_contato.telefone, 20, stdin);

                inserir_contato_lista(Contatos,novo_contato) ; break;
            case 2 : imprimir_contatos(Contatos);break ;
            case 3 :
                getchar();
                printf("Entre com o nome : ");
                fgets(nome,100,stdin);
               indice_busca = buscar_contato(Contatos,nome);
               if(indice_busca != -1){
                   printf("Contato encontrado:\n");
                   printf("Nome: %sEmail: %sTelefone: %s\n",
                          Contatos->contatos[indice_busca].nome,
                          Contatos->contatos[indice_busca].email,
                          Contatos->contatos[indice_busca].telefone);
                   int op = 0 ;
                   printf("----Entre com uma opcao----\n");
                   printf(" 1 para editar ou 2 para deletar : ");
                   scanf("%d",&op);

                   switch (op) {
                       case 1 :
                           getchar();
                           printf("Nome : ");
                           fgets(nome,200,stdin);
                           printf("Email : ");
                           fgets(email,50,stdin);
                           printf("Telefone : ");
                           fgets(telefone,20,stdin);
                           if(editar_contato(Contatos,indice_busca,nome,email,telefone) == 1){
                               printf("Editado Com Sucesso");
                           }else  if(editar_contato(Contatos,indice_busca,nome,email,telefone) == 0){
                               printf("Erro Ao Editar!");
                           }
                            break ;
                       case 2 :
                             deletar_contato(Contatos, indice_busca);
                           if(deletar_contato(Contatos,indice_busca == 1)){
                               printf("Deletado com Sucesso\n");
                           }else{
                               printf("Erro ao Deletar\n");
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











