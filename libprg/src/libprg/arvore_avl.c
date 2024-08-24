#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "libprg/libprg.h"

#define max(a,b)  (((a) > (b)) ? (a) : (b))

int contador_rotacoes = 0; // Variável global para contar rotações

// Função para calcular a altura de um nó
int altura(no_avl_t *v){
    if(v == NULL){
        return 0;
    } else{
        return v->altura;
    }
}

// Função para calcular o fator de balanceamento
int fator_balanceamento(no_avl_t *v){
    if(v == NULL){
        return 0;
    } else {
        return altura(v->esquerda) - altura(v->direita);
    }
}

// Rotação simples à esquerda
no_avl_t *rotacao_esquerda(no_avl_t *v){
    no_avl_t *u = v->direita;
    v->direita = u->esquerda;
    u->esquerda = v;
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;
    contador_rotacoes++; // Incrementa contador de rotações
    return u;
}

// Rotação simples à direita
no_avl_t *rotacao_direita(no_avl_t *v) {
    no_avl_t *u = v->esquerda;
    v->esquerda = u->direita;
    u->direita = v;
    v->altura = max(altura(v->esquerda), altura(v->direita)) + 1;
    u->altura = max(altura(u->esquerda), altura(u->direita)) + 1;
    contador_rotacoes++; // Incrementa contador de rotações
    return u;
}

// Função para criar um novo nó na árvore AVL
no_avl_t *criar_no_arvore_avl(int valor){
    no_avl_t *no = (no_avl_t *)malloc(sizeof(no_avl_t));
    no->altura = 1;
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

// Função para balancear a árvore AVL
no_avl_t *balancear(no_avl_t *v){
    int fb = fator_balanceamento(v);

    if (fb > 1) { // Nó desbalanceado à esquerda
        if (fator_balanceamento(v->esquerda) >= 0) {
            return rotacao_direita(v); // Caso esquerda-esquerda
        } else {
            return rotacao_dupla_direita(v); // Caso esquerda-direita
        }
    } else if (fb < -1) { // Nó desbalanceado à direita
        if (fator_balanceamento(v->direita) <= 0) {
            return rotacao_esquerda(v); // Caso direita-direita
        } else {
            return rotacao_dupla_esquerda(v); // Caso direita-esquerda
        }
    }

    return v;
}

// Rotação dupla à direita
no_avl_t *rotacao_dupla_direita(no_avl_t *v){
    v->esquerda = rotacao_esquerda(v->esquerda); // Rotação simples à esquerda no filho esquerdo
    return rotacao_direita(v); // Rotação simples à direita em v
}

// Rotação dupla à esquerda
no_avl_t *rotacao_dupla_esquerda(no_avl_t *v){
    v->direita = rotacao_direita(v->direita); // Rotação simples à direita no filho direito
    return rotacao_esquerda(v); // Rotação simples à esquerda em v
}

// Função para inserir um valor na árvore AVL
no_avl_t *inserir_arvore_avl(no_avl_t *v, int valor){
    if (v == NULL) {
        v = criar_no_arvore_avl(valor);
    } else if (valor < v->valor) {
        v->esquerda = inserir_arvore_avl(v->esquerda, valor);
    } else if (valor > v->valor) {
        v->direita = inserir_arvore_avl(v->direita, valor);
    }

    v->altura = 1 + max(altura(v->esquerda), altura(v->direita));
    v = balancear(v);
    return v;
}

// Função para remover um valor da árvore AVL
no_avl_t *remover_arvore_avl(no_avl_t *v, int valor) {
    if (v == NULL) {
        return NULL;
    } else if (valor < v->valor) {
        v->esquerda = remover_arvore_avl(v->esquerda, valor);
    } else if (valor > v->valor) {
        v->direita = remover_arvore_avl(v->direita, valor);
    } else { // valor == v->valor
        if (v->esquerda == NULL || v->direita == NULL) { // Nó folha ou nó com um filho
            no_avl_t *temp = v->esquerda ? v->esquerda : v->direita;
            if (temp == NULL) { // Nó folha
                temp = v;
                v = NULL;
            } else { // Nó com um filho
                *v = *temp; // Copia os dados do filho para o nó atual
            }
            free(temp);
        } else { // Nó com dois filhos
            no_avl_t *aux = v->esquerda;
            while (aux->direita != NULL) {
                aux = aux->direita;
            }
            v->valor = aux->valor;
            v->esquerda = remover_arvore_avl(v->esquerda, aux->valor);
        }
    }

    if (v == NULL) {
        return v;
    }

    v->altura = 1 + max(altura(v->esquerda), altura(v->direita)); // Atualiza a altura do nó atual
    return balancear(v); // Balanceia o nó atual
}
