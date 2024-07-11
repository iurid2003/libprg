#include <stdio.h>
#include "stdlib.h"
//como criar um ponteiro ?
// o que e ?

int main(){
    int dez = 10;
    int *num  ;

    num = &dez ;

    printf("%d\n",*num);
    printf("%p",num);
}