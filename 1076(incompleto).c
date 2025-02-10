#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 50

int grafo[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjacência
int grau[MAX_VERTICES];                // Grau de cada vértice
int visitado[MAX_VERTICES];            // Vetor de visitados para DFS

// Função de DFS para verificar se o grafo é conexo
void dfs(int v, int n) {
    visitado[v] = 1;
    for (int i = 0; i < n; i++) {
        if (grafo[v][i] && !visitado[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);  // Número de casos de teste

    while (T--) {
        int N, V, A;
        scanf("%d", &N);  // Nó inicial e final
        scanf("%d %d", &V, &A);  // Número de vértices e arestas

        // Inicializa a matriz de adjacência e o vetor de graus
        memset(grafo, 0, sizeof(grafo));
        memset(grau, 0, sizeof(grau));
        memset(visitado, 0, sizeof(visitado));

        // Lê as arestas e atualiza o grafo
        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            grafo[u][v] = 1;
            grafo[v][u] = 1;
            grau[u]++;
            grau[v]++;
        }

        // Verifica se o grafo é conexo
        dfs(N, V);
        int conexo = 1;
        for (int i = 0; i < V; i++) {
            if (!visitado[i] && grau[i] > 0) {  // Verifica apenas vértices com grau > 0
                conexo = 0;
                break;
            }
        }

        // Verifica o número de vértices com grau ímpar
        int vertices_impares = 0;
        for (int i = 0; i < V; i++) {
            if (grau[i] % 2 != 0) {
                vertices_impares++;
            }
        }

        // Calcula o número mínimo de movimentos
        int movimentos;
        if (conexo) {
            if (vertices_impares == 0) {
                // Grafo euleriano
                movimentos = A;
            } else if (vertices_impares == 2) {
                // Caminho euleriano
                movimentos = A;
            } else {
                // Não é euleriano, precisa repetir arestas
                movimentos = A + (vertices_impares - 2) / 2;
            }
        } else {
            // Grafo não é conexo, não é possível desenhar o labirinto
            movimentos = -1;
        }

        // Exibe o resultado
        if (movimentos == -1) {
            printf("Nao e possivel desenhar o labirinto.\n");
        } else {
            printf("%d\n", movimentos);
        }
    }

    return 0;
}
