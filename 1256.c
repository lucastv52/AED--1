#include <stdlib.h>
#include <stdio.h>

int main() {
    int N, M, C;
    scanf("%d", &N); 

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &M, &C); 

        int tabelaHash[M][C];  
        for (int k = 0; k < M; k++) {
            for (int l = 0; l < C; l++) {
                tabelaHash[k][l] = -1; 
            }
        }

        int contadores[M]; 
        for (int k = 0; k < M; k++) {
            contadores[k] = 0; 
        }

        for (int j = 0; j < C; j++) {
            int entrada;
            scanf("%d", &entrada); 
            int indice = entrada % M; 


            tabelaHash[indice][contadores[indice]] = entrada;
            contadores[indice]++; 
        }

        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < contadores[i]; j++) {
                printf(" %d ->", tabelaHash[i][j]);
            }
            printf(" \\\n");
        }

        if (i < N - 1) {
            printf("\n"); 
        }
    }

    return 0;
}
