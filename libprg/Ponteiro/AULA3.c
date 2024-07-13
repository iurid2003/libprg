#include <stdio.h>
#include <stdlib.h>

int main(void){
    char palavra[100];

    scanf("%100[^\n]",palavra);
    printf("%s\n",palavra);
}