


#include "libprg/libprg.h"


 lista_t *lista_tarefa() {
     srand(time(NULL));
     lista_t *tarefa= (lista_t *) malloc(sizeof(lista_t ));
    tarefa->tamanho = 0 ;
    tarefa->capacidade = 50 ;
    tarefa->Tarefas = (Tarefas_t *)calloc(tarefa->capacidade,sizeof(Tarefas_t));
    return tarefa;
}

int inserir_tarefa(lista_t * lista , Tarefas_t tarefas){

    lista->Tarefas[lista->tamanho++] = tarefas ;
    lista->Tarefas[lista->tamanho].ID = rand() % 1000 ; /// aqui eu gero um numero aleatorio pra servir como id de entrada
    return 1 ;
}


