#include <stdio.h>
#include <stdlib.h>


// alterando uma estrutura com ponteiro


typedef struct {
    int dia , mes ,ano ;
}data;

void altera_struct(data *data1){
    printf("%d/%d/%d\n",data1->dia,data1->mes,data1->ano);
     data1->ano = 25 ;
     data1->mes = 37 ;
     data1->dia = 25 ;
}


int main(void){

    data data1 ;
    data *p;

    p = &data1 ;
    data1.ano = 2023;
    data1.mes = 02 ;
    data1.dia = 01 ;
    printf("%d/%d/%d\n",data1.dia,data1.mes,data1.ano);
    printf("Data : %p , Conteudo : %p\n",&data1,p);

    altera_struct(p);

    printf("%d/%d/%d\n",data1.dia,data1.mes,data1.ano);
    printf("Data : %p , Conteudo : %p\n",&data1,p);


}