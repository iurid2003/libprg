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


typedef struct Contatos {
    char nome[100];
    char email[50];
    char telefone[20];
} Contatos_c;

typedef enum { SUM, SUB } operation_t;
//SOMA
result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

// LISTA
//typedef struct lista_a lista  ;
//lista * criar_lista();
//int busca_linear(lista ,int alvo);
//int busca_binaria( lista ,int tamanho, int alvo);
//int binario_recursivo( lista ,int i , int f ,int alvo);
//int* inserir_numero( lista ,int num );
//void removeNumero(lista, int num) ;

// FILA

//void enqueue(fila) ;
//void ler_contato(Contatos * c);

//LISTA CONTATO
typedef  struct  lista lista_c  ;
lista_c *lista_a();
void inserir_contato_lista(lista_c* lista , Contatos_c c);
void ler_contato(Contatos_c *c);
void imprimir_contatos(lista_c *lista);

// PILHA ;
//typedef  struct Pilha_a Pilha ;
//Pilha * Criar_Pilha();









#endif