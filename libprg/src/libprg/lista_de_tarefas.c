
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




void salvar_tarefas(lista_t * Tarefa){
    FILE* arquivo = fopen("contatos.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(&Tarefa->tamanho, sizeof(int), 1, arquivo);
    fwrite(Tarefa->Tarefas, sizeof(Tarefas_t),Tarefa->tamanho, arquivo);

    fclose(arquivo);
}
void carregar_tarefas(lista_t * Tarefa ){
    FILE* arquivo = fopen("contatos.dat", "rb");
    if (arquivo == NULL) {
        printf("Arquivo %s nao encontrado ou vazio.\n");
        return;
    }

    fread(&Tarefa->tamanho, sizeof(int), 1, arquivo);
    fread(Tarefa->Tarefas, sizeof(Tarefas_t), Tarefa->tamanho, arquivo);

    fclose(arquivo);
}

