//Lucas Tosetti de Vasconcellos RA 176577

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int origem, destino, peso;
} Aresta;

int compare(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}


int find(int parent[], int x) {
    if (parent[x] != x) 
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y) {
    int raizX = find(parent, x);
    int raizY = find(parent, y);

    if (raizX != raizY) {
        if (rank[raizX] > rank[raizY]) 
            parent[raizY] = raizX;
        else if (rank[raizX] < rank[raizY]) 
            parent[raizX] = raizY;
        else {
            parent[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int kruskal(Aresta arestas[], int cidades, int estradas) {
    qsort(arestas, estradas, sizeof(Aresta), compare);

    int parent[cidades], rank[cidades];
    for (int i = 0; i < cidades; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int custoTotal = 0, arestasSelecionadas = 0;

    for (int i = 0; i < estradas && arestasSelecionadas < cidades - 1; i++) {
        int u = arestas[i].origem;
        int v = arestas[i].destino;
        int peso = arestas[i].peso;

        if (find(parent, u) != find(parent, v)) {
            unionSet(parent, rank, u, v);
            custoTotal += peso;
            arestasSelecionadas++;
        }
    }

    return custoTotal;
}

int main() {
    int cidades, estradas;

    while (1) {
        scanf("%d %d", &cidades, &estradas);
        if (cidades == 0 && estradas == 0) break;

        Aresta arestas[estradas];
        int totalCusto = 0;

        for (int i = 0; i < estradas; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
            totalCusto += arestas[i].peso;
        }

        int custoMST = kruskal(arestas, cidades, estradas);
        printf("%d\n", totalCusto - custoMST);
    }

    return 0;
}
