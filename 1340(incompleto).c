#include <stdio.h>
#include <stdlib.h>




int main(){
    int n, x,y;
    int pilha, fila, heap = 0;
    
    while(pilha != 20){
        scanf("%d", &n);
        for(int i = 0; i<n; i++){
            int pilhas[n], filas[n], heaps[n], saida[n];
            scanf("%d %d", &x, &y);
            if(x == 1){
                pilhas[i] = y;
                filas[i] = y;
                heaps[i] = y;
            }else if(x == 2)
                saida[i] = y;

        }
    }
    return 0;
}
