#include <stdio.h>
#include <stdlib.h>

int verificaFila()


int main(){
    int n, x,y, t, s;
    int pilha, fila, heap = 0;
    
    while(pilha != 20){
        t, t1,t2,s,s1,s2 = 0;
        scanf("%d", &n);
        for(int i = 0; i<n; i++){
            int pilhas[n], filas[n], heaps[n], saida[n];
            scanf("%d %d", &x, &y);
            if(x == 1){
                filas[t++] = y;
                pilhas[t1++] = y;
                
            }else if(x == 2)
                saida[i] = y;

        }
    }
    return 0;
}
