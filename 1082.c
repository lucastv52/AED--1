//Lucas Tosetti de VAsconcellos RA 176577


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 26

int adj[MAX_V][MAX_V];
int visited[MAX_V];   
char vertices[MAX_V];  
int tam;              

void dfs(int u) {
    visited[u] = 1;
    vertices[tam++] = u; 
    for (int v = 0; v < MAX_V; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int compara(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int t = 1; t <= N; t++) {
        int V, E;
        scanf("%d %d", &V, &E);

       
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));

       
        for (int i = 0; i < E; i++) {
            char a, b;
            scanf(" %c %c", &a, &b); 
            int u = a - 'a'; 
            int v = b - 'a';
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        printf("Case #%d:\n", t);
        int num_components = 0;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                tam = 0; 
                dfs(i);

               
                qsort(vertices, tam, sizeof(char), compara);

               
                for (int j = 0; j < tam; j++) {
                    printf("%c,", vertices[j] + 'a'); 
                }
                printf("\n"); 
                num_components++;
            }
        }

        printf("%d connected components\n", num_components);
        printf("\n"); 
    }
    return 0;
}
