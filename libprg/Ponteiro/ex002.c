#include <stdlib.h>
#include <stdio.h>

void troca (float *a , float *b){
    float c ;
    c = *a ;
    *a = *b ;
    *b = c;




}


int main(void){
    float a = 10 ;
    float b = 4 ;
    printf("a : %.2f\n",a);
    printf("b : %.2f\n",b);

    troca(&a,&b);
    printf("a : %.2f\n",a);
    printf("b : %.2f\n",b);






}