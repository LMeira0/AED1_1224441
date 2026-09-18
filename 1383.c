/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Leonardo Freire Meira
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 20/08/2026
Objetivo    : Testar se a  sequencia do sudoku esta certa.
Dificuldade : Pensar na logica.
Uso de IA   : Nao
-------------------------------------------------------------------------- */
#include <stdio.h>
int x[9][9];

int valido(int a[9]){
    int visto[10] = {0};
    for (int i = 0; i < 9; i++) {
        int v = a[i];
        if (v < 1 || v > 9 || visto[v]) {
            return 0;
        }
        visto[v] = 1;
    }
    return 1;
}
int main() {
    int n, ok = 1;
    scanf("%d", &n);

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
            int coluna[9];
            for(int i = 0; i < 9; i++) {
                coluna[i] = x[i][j];
                ok = valido(coluna);
            }
        }     
        for(int i = 0; i < 9 && ok; i += 3) {
            for(int j = 0; j < 9 && ok; j += 3) {
                int bloco[9], r = 0;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        bloco[r++] = x[i + k][j + l];
                    }
                }
                ok = valido(bloco);
            }
        }
        printf("Instancia %d\n", f + 1);
        if(ok) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }
    return 0;
}
