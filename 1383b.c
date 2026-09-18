/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Freire Meira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Testar se a  sequencia do sudoku esta certa.
Dificuldade : Pensar na logica.
Uso de IA   : Ajudar a ver todas as partes que tinham que mudar.
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
int valido(int *a){
    int *visto = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        visto[i] = 0;
    }
    for (int i = 0; i < 9; i++) {
        int v = a[i];
        if (v < 1 || v > 9 || visto[v]) {
            return 0;
        }
        visto[v] = 1;
    }
    free(visto);
    return 1;
}
int main() {
    int n, ok = 1;
    scanf("%d", &n);

    int **x = (int **)malloc(9 * sizeof(int *));
    for (int i = 0; i < 9; i++) {
        x[i] = (int *)malloc(9 * sizeof(int));
    }

    for(int f = 0; f < n; f++) {

        for(int i = 0; i <  9; i++) {
            for(int j = 0; j < 9; j++) {
                scanf("%d", &x[i][j]);
            }
        }
        for(int i = 0; i < 9; i++) {
            ok = valido(x[i]);
        }
        for(int j = 0; j < 9 && ok; j++) {
            int *coluna = (int *)malloc(9 * sizeof(int));
            for(int i = 0; i < 9; i++) {
                coluna[i] = x[i][j];
            }
            ok = valido(coluna);
            free(coluna);
        }     
        for(int i = 0; i < 9 && ok; i += 3) {
            for(int j = 0; j < 9 && ok; j += 3) {
                int *bloco = (int *)malloc(9 * sizeof(int));
                int r = 0;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        bloco[r++] = x[i + k][j + l];
                    }
                }
                ok = valido(bloco);
                free(bloco);
            }
        }
        printf("Instancia %d\n", f + 1);
        if(ok) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    for (int i = 0; i < 9; i++) {
        free(x[i]);
    }
    free(x);

    return 0;
}
