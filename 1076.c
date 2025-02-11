//Lucas Tosetti de vasconcellos RA 176577

#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 50

int grafo[MAX_VERTICES][MAX_VERTICES];  
int visitado[MAX_VERTICES];            
int ans;                              

void dfs(int v, int n) {
    visitado[v] = 1;  
    for (int i = 0; i < n; i++) {
        if (grafo[v][i] && !visitado[i]) {  
            dfs(i, n); 
            ans++;     
        }
    }
}

int main() {
    int T;
    scanf("%d", &T); 

    while (T--) {
        int N, V, A;
        scanf("%d", &N);  
        scanf("%d %d", &V, &A); 

       
        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));
        ans = 0;  

        
        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u][v] = 1;
            grafo[v][u] = 1;
        }

     
        dfs(N, V);

       
        printf("%d\n", ans * 2);
    }

    return 0;
}
