//Lucas Tosetti de Vasconcellos RA: 176577

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

typedef struct {
    int c, d;
} node;

typedef struct {
    node h[250*250];
    int sz;
} minheap;

void initHeap(minheap *q) {
    q->sz = 0;
}

void insertHeap(minheap *q, int c, int d) {
    int i = q->sz++;
    while (i > 0 && d < q->h[(i - 1) / 2].d) {
        q->h[i] = q->h[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    q->h[i].c = c;
    q->h[i].d = d;
}

node removeHeap(minheap *q) {
    node root = q->h[0];
    node last = q->h[--q->sz];
    int i = 0, child;
    while (2 * i + 1 < q->sz) {
        child = 2 * i + 1;
        if (child + 1 < q->sz && q->h[child + 1].d < q->h[child].d) {
            child++;
        }
        if (last.d <= q->h[child].d) break;
        q->h[i] = q->h[child];
        i = child;
    }
    q->h[i] = last;
    return root;
}

int dijkstra(int N, int C, int K, int g[250][250]) {
    minheap q;
    initHeap(&q);
    int dist[250];
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX; 
    }
    dist[K] = 0;
    insertHeap(&q, K, 0);
    
    while (q.sz > 0) {
        node cur = removeHeap(&q);
        int c = cur.c, d = cur.d;
        if (c == C - 1) return d;
        if (d > dist[c]) continue;
        
        if (c < C - 1) {
            int nxt = c + 1;
            if (dist[nxt] > d + g[c][nxt]) {
                dist[nxt] = d + g[c][nxt];
                insertHeap(&q, nxt, dist[nxt]);
            }
        } else {
            for (int v = 0; v < N; v++) {
                if (g[c][v] != INT_MAX) { 
                    int new_d = d + g[c][v];
                    if (dist[v] > new_d) {
                        dist[v] = new_d;
                        insertHeap(&q, v, new_d);
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int N, M, C, K;
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;
        int g[250][250];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] = INT_MAX; 
            }
        }
        for (int i = 0; i < M; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            g[u][v] = p;
            g[v][u] = p;
        }
        printf("%d\n", dijkstra(N, C, K, g));
    }
    return 0;
}
