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
    int value;
    struct no* next;
} no;

typedef struct {
    no* head;
    no* tail;
    int size;
} fila;

void initfila(fila *q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void push(fila *q, int val) {
    no *novono = (no*)malloc(sizeof(no));
    novono->value = val;
    novono->next = NULL;

    if (q->tail == NULL) {
        q->head = novono;
        q->tail = novono;
    } else {
        q->tail->next = novono;
        q->tail = novono;
    }
    q->size++;
}

int pop(fila* q) {
    no* temp;
    int val;

    if (q->head == NULL) return -1;

    temp = q->head;
    val = temp->value;

    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    q->size--;

    return val;
}

int main() {
    int n;
    int i;
    int first;
    fila cards;

    while (scanf("%d", &n) == 1 && n != 0) {
        initfila(&cards);

        // Preenche a fila
        for (i = 1; i <= n; i++) {
            push(&cards, i);
        }

        printf("Discarded cards:");
        first = 1;

        // Simulação do descarte
        while (cards.size > 1) {
            if (!first) {
                printf(",");
            }
            printf(" %d", pop(&cards));
            first = 0;

            push(&cards, pop(&cards));
        }

        printf("\nRemaining card: %d\n", pop(&cards));
    }

    return 0;
}
