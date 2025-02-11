#include <stdio.h>
#include <string.h>

#define MAX_N 52


typedef struct Node {
    char valor;
    struct Node *esquerda, *direita;
} Node;


Node* construirArvore(char *pre, char *in, int inicio, int fim, int *preIndex) {
    if (inicio > fim) return NULL;

    
    Node *novoNo = (Node*) malloc(sizeof(Node));
    novoNo->valor = pre[(*preIndex)++];
    novoNo->esquerda = novoNo->direita = NULL;

    
    if (inicio == fim) return novoNo;

    
    int inIndex;
    for (inIndex = inicio; inIndex <= fim; inIndex++) {
        if (in[inIndex] == novoNo->valor) break;
    }

    
    novoNo->esquerda = construirArvore(pre, in, inicio, inIndex - 1, preIndex);
    novoNo->direita = construirArvore(pre, in, inIndex + 1, fim, preIndex);

    return novoNo;
}


void imprimirPosOrdem(Node *raiz) {
    if (raiz == NULL) return;
    imprimirPosOrdem(raiz->esquerda);
    imprimirPosOrdem(raiz->direita);
    printf("%c", raiz->valor);
}


int main() {
    int C; 
    scanf("%d", &C);

    while (C--) {
        int N;
        char pre[MAX_N + 1], in[MAX_N + 1];

        
        scanf("%d %s %s", &N, pre, in);

        
        int preIndex = 0;

        
        Node *raiz = construirArvore(pre, in, 0, N - 1, &preIndex);

        
        imprimirPosOrdem(raiz);
        printf("\n");
    }

    return 0;
}
