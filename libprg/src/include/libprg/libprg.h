#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);
// LISTA
int lista(int n,int tamanho);
#endif
