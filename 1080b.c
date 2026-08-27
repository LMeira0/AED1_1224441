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
