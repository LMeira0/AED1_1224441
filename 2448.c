#include <stdio.h>
#include <stdlib.h> 

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
    int n, m, i;
    
    scanf("%d %d", &n, &m);
    
    int v[n];
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    
    int tempo_total = 0;
    int posicao_atual = 0; 
    
    for(i = 0; i < m; i++){
        int destino_numero;
        scanf("%d", &destino_numero);
        
    
        int indice_destino = buscabinaria(n, destino_numero, v);
        
        
        tempo_total += abs(indice_destino - posicao_atual);
        
        
        posicao_atual = indice_destino;
    }
    
    printf("%d\n", tempo_total);
    
    return 0;
}
