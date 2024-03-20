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

typedef struct lista_a lista  ;
typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

// LISTA
void crar_lista();
int  busca_linear(lista_a lista ,int alvo);
int busca_binaria(lista_a lista ,int tamanho, int alvo);
int binario_recursivo(lista_a  lista ,int i , int f ,int alvo);
int* inserir_numero(lista_a lista ,int num );
void removeNumero(lista_a lista, int num);

#endif
