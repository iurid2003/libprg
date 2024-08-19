#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;
//SOMA
result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

// LISTA
typedef struct lista_l {
    int tamanho ;
    int capacidade;
    int *vetor ;
    bool vazio ;

}lista_linear;
lista_linear * criar_lista();
//void inserir(lista_linear*listaLinear , int n);
int retirar(lista_linear*listaLinear, int n);
void imprimir(lista_linear*listaLinear);
int buscar(lista_linear*listaLinear , int n);
int busca_binaria_it(lista_linear*listaLinear, int n);
int busca_binaria_rec(lista_linear*listaLinear, int inicio , int fim , int num);



//LISTA CIRCULAR ENCADEADA  (ORDENADA E NAO ORDENADA)






//LISTA CIRCULAR DUPLAMENTE ENCADEADA (ORDENADA E NAO ORDENADA)



// PILHA
//typedef struct Pilha_a Pilha ;
//Pilha* Criar_Pilha();
//void push(Pilha *p , int n);
//void pop(Pilha *p);
//int size(Pilha *p );
//void empty(Pilha *p);
//void imprimir_pilha(Pilha *p);

//PILHA ENCADEADA

//typedef struct  no No_p ;
//dado d();
//void imprimir_dado_p(dado dado1);
//void imprimir_pilha(No_p * topo);
//No_p * empillhar (No_p * topo);
//No_p * desempilhar(No_p ** topo);


// FILA

//typedef struct Fila_a Fila ;
//Fila *criar_fila();
//bool full(Fila *fila);
//bool empty(Fila *fila);
//bool enqueue(Fila *fila, int n);
//int dequeue(Fila *fila);
//int head(Fila *fila);
//int tail(Fila *fila);
//int size(Fila *fila);

//FILA ENCADEADA

//typedef struct no_f No_f;
//void inserir_fila(No_f**fila, int num);
//No_f * remover_da_fila(No_f ** fila);
//void imprimir_fila(No_f * fila);
//void elemento_inicio_fila(No_f * fila);
//void elemento_fim_fila(No_f * fila);
//void tamanho_fila_encadeada(No_f * fila);
//void fila_vazia(No_f * fila);


//LISTA CONTATO

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

lista_c *criar_contato();
int inserir_contato_lista(lista_c* lista , Contatos_c c) ;
int editar_contato(lista_c * lista , int pos_lista,char * nome , char * email , char * telefone );
int deletar_contato(lista_c * lista , int indice);
void imprimir_contatos(lista_c *lista);
int buscar_contato(lista_c  * lista, char nome[100]);
void salvar_contatos(lista_c * Contato);
void carregar_contatos(lista_c * Contato);

// PILHA


//typedef  struct Pilha_a Pilha ;
//Pilha * Criar_Pilha();


// Lista encadeada
//typedef  struct no no_t ;
//void adicionar_no(no_t ** inicio, int dado) ;
//no_t  * remove_no(no_t ** inicio , int dado);
//void ordena_no(no_t ** lista ,int dado);
//void destruir(no_t ** inicio);
//no_t  * buscar(no_t ** inicio , int dado);
//int getretorna_elementos(no_t ** inicio);

//


//alg_ord_troca
void selection_sort(int *vet, int tamanho);
int *insertion_sort(int *vetor, int tamanho);
void burble_sort(int vetor[], int tamanho);

//algo_ord_div
int *merge_sort(int *vet, int esquerda, int direita);
int  *quicksort(int *vet, int inicio, int fim);

//TABELA HASH CONTATOS

typedef struct {
    char *cpf;
    char *nome;
    char *email;
} pessoa_t;

typedef struct no{
    char  * chave;
    pessoa_t *valor ;
    struct no * prox;
}no_t;

typedef struct dicionario{
    int tamanho ;
    no_t ** vetor;
}dicionario_t;

//LISTA TAREFAS




//typedef struct Tarefas {
//    char tarefa[200]; // tipo de tarefa
//    int prioridade; // prioridade ALTA , MEDIA , BAIXA
//    char prazo[20]; // dia que vai concluir
//    char prazo_conclusao[20]; // dia que concluiu
//    int ID ;
//} Tarefas_t;
//
//typedef struct lista_tarefas {
//    int tamanho; // TAMANHO QUE A LISTA DE TAREFAS
//    int capacidade; // CAPACIDADE DA LISTA DE TAREFAS
//    Tarefas_t * Tarefas; // VETOR DE ESTRUTURAS DE TAREFAS
//} lista_t;
//
//lista_t *criar_tarefa();
//int inserir_tarefa(lista_t * lista_tarefas , Tarefas_t Tarefas);
//void salvar_tarefas(lista_t * Tarefas);
//void carregar_tarefas(lista_t * Tarefas );

//dicionario_t *criar_dicionario(int m);
//void destruir_pessoa(pessoa_t *pessoa);
//void destruir_dicionario(dicionario_t *d);
//bool inserir(dicionario_t *d, char *chave, pessoa_t *valor);

// Arvore Avl

typedef struct no_avl{
    int valor ;
    int altura;
    struct  no_avl* esquerda ;
    struct  no_avl* direita ;
} no_avl_t;

int altura(no_avl_t *v);
int fator_balanceamento(no_avl_t *v);
no_avl_t  * rotacao_esquerda(no_avl_t *v);
no_avl_t *rotacao_direita(no_avl_t *v);
no_avl_t *criar_no_arvore_avl(int valor);
no_avl_t  * inserir_arvore_avl(no_avl_t *v, int valor);
no_avl_t  * balancear(no_avl_t *v);
no_avl_t *rotacao_dupla_direita(no_avl_t *v);
no_avl_t *rotacao_dupla_esquerda(no_avl_t *v);
no_avl_t *remover(no_avl_t *v, int valor);


#endif