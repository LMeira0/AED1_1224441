/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Freire Meira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 18/09/2026
Objetivo    : fazer o reordenamento das cartas de um baralho.
Dificuldade : Entender como usar listas encadeadas
Uso de IA   : Dizer o que tinha que fazer e ensinar esses novos comandos de listas encadeadas.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no;

typedef struct {
    no* cabeca;
    no* fim;
    int tamanho;
} fila;

void initfila(fila *q) {
    q->cabeca = NULL;
    q->fim = NULL;
    q->tamanho = 0;
}

void insercaofim(fila *q, int val) {
    no *novono = (no*)malloc(sizeof(no));
    novono->valor = val;
    novono->proximo = NULL;

    if (q->fim == NULL) {
        q->cabeca = novono;
        q->fim = novono;
    } else {
        q->fim->proximo = novono;
        q->fim = novono;
    }
    q->tamanho++;
}

int remocaoinicio(fila* q) {
    no* temp;
    int val;

    if (q->cabeca == NULL) return -1;

    temp = q->cabeca;
    val = temp->valor;

    q->cabeca = q->cabeca->proximo;

    if (q->cabeca == NULL) {
        q->fim = NULL;
    }

    free(temp);
    q->tamanho--;

    return val;
}

int main() {
    int n;
    int i;
    int primeiro;
    fila cartas;

    while (scanf("%d", &n) == 1 && n != 0) {
        initfila(&cartas);

        for (i = 1; i <= n; i++) {
            insercaofim(&cartas, i);
        }

        printf("Discarded cards:");
        primeiro = 1;

        while (cartas.tamanho > 1) {
            if (!primeiro) {
                printf(",");
            }
            printf(" %d", remocaoinicio(&cartas));
            primeiro = 0;

            insercaofim(&cartas, remocaoinicio(&cartas));
        }

        printf("\nRemaining card: %d\n", remocaoinicio(&cartas));
    }

    return 0;
}
