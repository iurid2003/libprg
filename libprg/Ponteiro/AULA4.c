#include <stdio.h>
#include <stdlib.h>

// como passar ponteiro para uma funcao ou procedimento

void imprimir(int *n){

    printf("%d\n",*n);
    *n = 80 ;
}

int main(void){
    int idade = 35 ;


    imprimir(&idade);
    printf("%d\n",idade);


}