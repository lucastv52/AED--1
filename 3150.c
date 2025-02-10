//Lucas Tosetti de Vasconcellos RA 176577


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000

int grafo[MAX_N][MAX_N];  
int grau[MAX_N];          
int visitado[MAX_N];      


void dfs(int v, int n) {
    visitado[v] = 1;
    for (int i = 0; i < n; i++) {
        if (grafo[v][i] && !visitado[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

   
    memset(grafo, 0, sizeof(grafo));
    memset(grau, 0, sizeof(grau));
    memset(visitado, 0, sizeof(visitado));

   
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        grafo[u][v] = 1;
        grafo[v][u] = 1;
        grau[u]++;
        grau[v]++;
    }

  
    int todos_grau_par = 1;
    for (int i = 0; i < n; i++) {
        if (grau[i] % 2 != 0) {
            todos_grau_par = 0;
            break;
        }
    }

  
    dfs(0, n);
    int conexo = 1;
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            conexo = 0;
            break;
        }
    }

   
    if (todos_grau_par && conexo) {
        printf("Rambo esta salvo\n");
    } else {
        printf("Rambo esta perdido\n");
    }

    return 0;
}
