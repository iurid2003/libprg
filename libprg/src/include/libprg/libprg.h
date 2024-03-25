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
typedef struct lista_a lista  ;
int criar_lista();
int busca_linear(lista ,int alvo);
int busca_binaria( lista ,int tamanho, int alvo);
int binario_recursivo( lista ,int i , int f ,int alvo);
int* inserir_numero( lista ,int num );
void removeNumero(lista, int num) ;

// FILA

typedef struct fila_a fila;
void enfirelar(fila);
void desenfilerar(fila);
void imprime_fila(fila);
int inicio(fila);
int fim(fila);
int tam(fila);
int vazia(fila);
int cheia(fila);

#endif