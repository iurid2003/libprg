
#include "libprg/libprg.h"


 lista_t *criar_tarefa() {
     srand(time(NULL));
     lista_t *Tarefas= (lista_t *) malloc(sizeof(lista_t ));
    Tarefas->tamanho = 0 ;
    Tarefas->capacidade = 50 ;
    Tarefas->Tarefas = (Tarefas_t *)malloc(sizeof(Tarefas_t)*Tarefas->capacidade);
    return Tarefas;
}


int inserir_tarefa(lista_t * lista , Tarefas_t Tarefas){
    Tarefas.ID = rand() % 1000 ; /// aqui eu gero um numero aleatorio pra servir como id de entrada
    lista->Tarefas[lista->tamanho++] = Tarefas ;
    return 1 ;
}


void salvar_tarefas(lista_t * Tarefas){
    FILE* arquivo = fopen("Tarefasd.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(&Tarefas->tamanho, sizeof(int), 1, arquivo);
    fwrite(Tarefas->Tarefas, sizeof(Tarefas_t),Tarefas->tamanho, arquivo);

    fclose(arquivo);
}
void carregar_tarefas(lista_t * Tarefas ){
    FILE* arquivo = fopen("Tarefas.dat", "rb");
    if (arquivo == NULL) {
        printf("Arquivo %s nao encontrado ou vazio.\n");
        return;
    }

    fread(&Tarefas->tamanho, sizeof(int), 1, arquivo);
    fread(Tarefas->Tarefas, sizeof(Tarefas_t), Tarefas->tamanho, arquivo);

    fclose(arquivo);
}

