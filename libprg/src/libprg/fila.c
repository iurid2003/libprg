#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Definição da estrutura da Fila
typedef struct Fila_a {
    int *vet;  // Vetor que armazena os elementos da fila
    int tam;   // Tamanho da fila
    int inicio; // Índice do início da fila
    int fim;    // Índice do fim da fila
    int qtde;   // Quantidade de elementos na fila
} Fila;

// Função para criar a fila
Fila *criar_fila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila)); // Aloca memória para a estrutura Fila
    if (fila != NULL) {
        fila->inicio = 0;
        fila->fim = 0;
        fila->tam = 10;
        fila->qtde = 0; // Inicia com zero elementos
        fila->vet = malloc(sizeof(int) * fila->tam); // Aloca memória para o vetor da fila
        if (fila->vet == NULL) {
            free(fila); // Libera a memória da estrutura Fila em caso de erro
            printf("Nao foi Possivel Alocar Memoria\n");
            return NULL;
        }
    } else {
        printf("Nao foi Possivel Alocar Memoria\n");
        return NULL;
    }
    return fila; // Retorna a fila criada
}

// Função para verificar se a fila está cheia
bool full(Fila *fila) {
    return fila->qtde == fila->tam;
}

// Função para verificar se a fila está vazia
bool empty(Fila *fila) {
    return fila->qtde == 0;
}

// Função para inserir um elemento na fila (enqueue)
bool enqueue(Fila *fila, int n) {
    if (full(fila)) {
        printf("Fila cheia!\n");
        return false; // Fila cheia
    }
    fila->vet[fila->fim] = n; // Insere o elemento no fim da fila
    fila->fim = (fila->fim + 1) % fila->tam; // Atualiza o índice do fim, considerando a circularidade
    fila->qtde++; // Incrementa a quantidade de elementos na fila
    return true;
}

// Função para remover um elemento da fila (dequeue)
int dequeue(Fila *fila) {
    if (empty(fila)) {
        printf("Fila vazia!\n");
        return -1; // Fila vazia
    }
    int elemento = fila->vet[fila->inicio]; // Obtém o elemento do início da fila
    fila->inicio = (fila->inicio + 1) % fila->tam; // Atualiza o índice do início, considerando a circularidade
    fila->qtde--; // Decrementa a quantidade de elementos na fila
    return elemento;
}

// Função para obter o elemento no início da fila (head)
int head(Fila *fila) {
    if (empty(fila)) {
        printf("Fila vazia!\n");
        return -1; // Fila vazia
    }
    return fila->vet[fila->inicio]; // Retorna o elemento no início da fila
}

// Função para obter o elemento no fim da fila (tail)
int tail(Fila *fila) {
    if (empty(fila)) {
        printf("Fila vazia!\n");
        return -1; // Fila vazia
    }
    return fila->vet[(fila->fim - 1 + fila->tam) % fila->tam]; // Retorna o elemento no fim da fila
}

// Função para obter o tamanho atual da fila (size)
int size(Fila *fila) {
    return fila->qtde; // Retorna a quantidade de elementos na fila
}

// Função para liberar a memória alocada para a fila
void liberar_fila(Fila *fila) {
    free(fila->vet); // Libera a memória do vetor da fila
    free(fila); // Libera a memória da estrutura Fila
}

int main() {
    Fila *fila = criar_fila(10); // Cria a fila com tamanho 10
    if (fila != NULL) {
        enqueue(fila, 1); // Insere elementos na fila
        enqueue(fila, 2);
        enqueue(fila, 3);

        printf("Elemento no início: %d\n", head(fila)); // Imprime o elemento no início da fila
        printf("Elemento no fim: %d\n", tail(fila)); // Imprime o elemento no fim da fila
        printf("Tamanho da fila: %d\n", size(fila)); // Imprime o tamanho da fila

        printf("Elemento removido: %d\n", dequeue(fila)); // Remove e imprime um elemento da fila
        printf("Elemento removido: %d\n", dequeue(fila)); // Remove e imprime um elemento da fila

        // Libera a memória alocada
        liberar_fila(fila);
    }
    return 0;
}
