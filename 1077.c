#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = c;
    }
}

char pop(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0';
}

char espiarTopo(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[p->topo];
    }
    return '\0';
}

int precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixaParaPosfixa(const char *expr) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; expr[i] != '\0' && expr[i] != '\n' && expr[i] != '\r'; i++) {
        char c = expr[i];

        if (isalnum(c)) {
            putchar(c);
        }
        else if (c == '(') {
            push(&p, c);
        }
        else if (c == ')') {
            while (!estaVazia(&p) && espiarTopo(&p) != '(') {
                putchar(pop(&p));
            }
            if (!estaVazia(&p) && espiarTopo(&p) == '(') {
                pop(&p);
            }
        }
        else {
            while (!estaVazia(&p) && espiarTopo(&p) != '(' && precedencia(espiarTopo(&p)) >= precedencia(c)) {
                putchar(pop(&p));
            }
            push(&p, c);
        }
    }

    while (!estaVazia(&p)) {
        putchar(pop(&p));
    }
    putchar('\n');
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char expr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%s", expr);
        infixaParaPosfixa(expr);
    }

    return 0;
}
