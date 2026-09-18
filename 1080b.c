/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Freire Meira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Ler 100 numeros e dizer qual eh o maior e sua posicao desde que sejam inteiros, positivos e distintos.
Dificuldade : Nenhum
Uso de IA   : Nao
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
 
int main() {
    
    int i, maior, pos = 1, *x;
    
    x = (int *) malloc(100);
    if(x == 0) {
        printf("erro");
        return 1;
    }
    scanf("%d", &x[0]);
    maior = x[0];
    
    for (i = 1; i < 100; i++) {
        scanf("%d", &x[i]);
        
        if (x[i] < 0) {
            return 0;
        }
        
        if (x[i] > maior) {
            maior = x[i];
            pos = i + 1;
        }
    }
    
    printf("%d\n", maior);
    printf("%d\n", pos);
    free(x);
    return 0;
}
