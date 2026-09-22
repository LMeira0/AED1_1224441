/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Freire Meira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 20/09/2026
Objetivo    : saber se a quantidade de parênteses está balanceada.
Dificuldade : Entender como usar pilhas
Uso de IA   : Dizer o que tinha que fazer e ensinar esses novos comandos de pilhas.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char data;
    struct no *proximo;
} no;

typedef struct {
    no *cabeca;
} pilha;

void initpilha(pilha *s) {
    s->cabeca = NULL;
}

int vazio(pilha *s) {
    return s->cabeca == NULL;
}

void empilha(pilha *s, char val) {
    no *novono = (no*)malloc(sizeof(no));
    novono->data = val;
    novono->proximo = s->cabeca; 
    s->cabeca = novono;        
}

char desempilha(pilha *s) {
    no *temp;
    char val;

    if (vazio(s)) return '\0';

    temp = s->cabeca;
    val = temp->data;
    s->cabeca = s->cabeca->proximo; 
    free(temp);            

    return val;
}

void clearStack(pilha *s) {
    while (!vazio(s)) {
        desempilha(s);
    }
}

int balanceado(const char *expr) {
    pilha s;
    int i;
    int ok;

    initpilha(&s);
    ok = 1;

    for (i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') {
            empilha(&s, '(');
        } else if (expr[i] == ')') {
            if (vazio(&s)) {
                ok = 0;
                break;
            }
            desempilha(&s);
        }
    }

    if (!vazio(&s)) {
        ok = 0;
    }

    clearStack(&s);
    return ok;
}

int main() {
    char buffer[1005];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (balanceado(buffer)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
