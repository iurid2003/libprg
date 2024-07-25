


#include "libprg/libprg.h"


lista_t *lista_tarefa() {
    lista_t *tarefa= (lista_t *) malloc(sizeof(lista_t ));
    tarefa->tamanho = 0 ;
    tarefa->capacidade = 50 ;
    tarefa->Tarefas = (Tarefas_t *)calloc(tarefa->capacidade,sizeof(Tarefas_t));
    return tarefa;
}


