#include <stdio.h>
#include <stdlib.h>



int main(void){
    int A , *B , **C , ***D ;
    printf("Entre com um numero : ");
    scanf("%d",&A);
    B = &A;
    C = &B;
    D = &C;

    printf("Dobro de %d : %d\n",A,*B*2);
    printf("Triplo de %d : %d\n",**C,**C*3);
    printf("Quadruplo de %d : %d",***D,***D*4);
}
