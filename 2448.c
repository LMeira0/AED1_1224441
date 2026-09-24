#include <stdio.h>

int buscabinaria(int n, int x, int v[]){
    int e, m, d;
    e = -1; 
    d = n;
    while(e < d - 1){
       m = (e + d) / 2;
       if(v[m] < x){
        e = m;
       }
       else{
        d = m;
       }
    }
    return d;
}
int main(){
    int n, x, i;
    scanf("%d", &n);
    int v[n];
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    scanf("%d", &x);
    printf("%d\n", buscabinaria(n, x, v));
    return 0;
}
