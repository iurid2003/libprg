#include <stdlib.h>
#include <stdio.h>

// Ponteiro pra ponteiro

int main(void){

    int A = 100 ,*B , **C ;
    B = &A ;
    C = &B ;

    printf("Endereco de A : %p -- Conteudo de A : %d",&A,A);
    printf("\n");
    printf("Endereco de B : %p -- Coteudo de B : %p",&B,B);
    printf("\n");
    printf("Coteudo de B : %d\n",*B);
    printf("Endereco de C: %p -- Coteudo de C : %p\n",&C,C);
    printf("Coteudo de C : %d",**C);





}