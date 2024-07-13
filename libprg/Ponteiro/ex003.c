#include <stdio.h>
#include <stdlib.h>


int main(void){
    int i , vet[10] ={1,2,3,4,5,6,7,8,9,10};

    for (int j = 0; j < 10; ++j) {
        printf("%p -  %d\n",vet + j,*(vet + j));
    }

}