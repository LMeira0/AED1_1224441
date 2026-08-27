#include <stdio.h>
 
int main() {
    
    int x[100], i, maior, pos = 1;
    
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
    return 0;
}
