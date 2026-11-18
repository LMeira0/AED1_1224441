/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Leonardo Freire Meira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : Verificar se existe um ciclo de dependências entre os documentos.
Dificuldade : Montar o grafo com lista encadeada e detectar ciclos usando DFS.
Uso de IA   : Explicar a lógica para achar ciclos em grafos e estruturar o código.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

typedef struct No {
    int destino;
    struct No* prox;
} No;

No* grafo[MAX];
int estado[MAX];

void adicionar_aresta(int u, int v) {
    No* novo = (No*) malloc(sizeof(No));
    novo->destino = v;
    novo->prox = grafo[u];
    grafo[u] = novo;
}

int tem_ciclo(int u) {
    estado[u] = 1;

    No* atual = grafo[u];
    while (atual != NULL) {
        int v = atual->destino;

        if (estado[v] == 1) {
            return 1;
        }

        if (estado[v] == 0 && tem_ciclo(v)) {
            return 1;
        }

        atual = atual->prox;
    }

    estado[u] = 2;
    return 0;
}

void limpar_grafo(int n) {
    for (int i = 1; i <= n; i++) {
        No* atual = grafo[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        grafo[i] = NULL;
        estado[i] = 0;
    }
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++) {
            grafo[i] = NULL;
            estado[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adicionar_aresta(a, b);
        }

        int encontrou_ciclo = 0;
        for (int i = 1; i <= n; i++) {
            if (estado[i] == 0) {
                if (tem_ciclo(i)) {
                    encontrou_ciclo = 1;
                    break;
                }
            }
        }

        if (encontrou_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        limpar_grafo(n);
    }

    return 0;
}
