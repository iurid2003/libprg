#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
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
void inserir(lista_linear*listaLinear , int n);
int retirar(lista_linear*listaLinear, int n);
void imprimir(lista_linear*listaLinear);
int buscar(lista_linear*listaLinear , int n);
int busca_binaria_it(lista_linear*listaLinear, int n);
int busca_binaria_rec(lista_linear*listaLinear, int inicio , int fim , int num);


// PILHA
typedef struct Pilha_a Pilha ;
Pilha* Criar_Pilha();
void push(Pilha *p , int n);
void pop(Pilha *p);
int size(Pilha *p );
void empty(Pilha *p);
void imprimir_pilha(Pilha *p);

//PILHA ENCADEADA
typedef struct {
    int num ;
}dado;

typedef struct  no No_p ;
dado d();
void imprimir_dado(dado dado1);
void imprimir( No_p * topo);
No_p * empillhar (No_p * topo);
No_p * desempilhar(No_p ** topo);


// FILA

typedef struct Fila_a Fila ;
Fila *criar_fila();
bool full(Fila *fila);
bool empty(Fila *fila);
bool enqueue(Fila *fila, int n);
int dequeue(Fila *fila);
int head(Fila *fila);
int tail(Fila *fila);
int size(Fila *fila);

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
typedef  struct no no_t ;
void adicionar_no(no_t ** inicio, int dado) ;
no_t  * remove_no(no_t ** inicio , int dado);
void ordena_no(no_t ** lista ,int dado);
void destruir(no_t ** inicio);
no_t  * buscar(no_t ** inicio , int dado);
int getretorna_elementos(no_t ** inicio);

//
typedef struct  lista_a Lista ;
Lista * criar_lista(bool ordenado);
void adiciona_lista( Lista * lista, int dado);
void inserir_ordenado_lista(Lista * lista , int dado);
no_t  * remover(Lista * lista , int dado);
no_t * buscar_lista(Lista * lista , int dado);
int *get_elementos(Lista * lista);
int get_tamanho(Lista * lista);

//alg_ord_troca
void selection_sort(int *vet, int tamanho);
int *insertion_sort(int *vetor, int tamanho);
void burble_sort(int vetor[], int tamanho);

//algo_ord_div






#endif