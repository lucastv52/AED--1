//Lucas Tosetti de Vasconcellos RA:176577

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
    char num;    // Conteúdo do nó
    struct cel *seg;    // Ponteiro que aponta para o próximo nó
};
typedef struct cel celula;

void empilhar(char y, celula *p) { // Insere uma célula de valor Y após a cabeça
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->num = y;
    nova->seg = p->seg;
    p->seg = nova;
}

char Desempilha(celula *p) {
    char x;
    celula *q;
    q = p->seg;
    x = q->num;
    p->seg = q->seg;
    free(q);
    return x;
}

int ordem(char operador) {
    if (operador == '+' || operador == '-')
        return 0;
    else if (operador == '/' || operador == '*')
        return 1;
    else if (operador == '^')
        return 2;
    else
        return -1; // Caso inválido
}

void inserir(char valor, celula *p) { // Cria uma nova célula após a célula P
    celula *nova = malloc(sizeof(celula));
    nova->num = valor;
    nova->seg = p->seg; // Manipula os ponteiros
    p->seg = nova;
}

void imprimir_invertido(celula *lista) {
    // Pilha auxiliar para imprimir em ordem correta
    celula *pilha_aux = malloc(sizeof(celula));
    pilha_aux->seg = NULL;

    // Transferir elementos da lista para a pilha auxiliar
    celula *p = lista->seg;
    while (p != NULL) {
        empilhar(p->num, pilha_aux);
        p = p->seg;
    }

    // Imprimir elementos da pilha auxiliar
    while (pilha_aux->seg != NULL) {
        printf("%c", Desempilha(pilha_aux));
    }
    printf("\n");

    free(pilha_aux);
}

int main() {
    celula *cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;
    celula *saida = malloc(sizeof(celula));
    saida->seg = NULL;

    int n;
    scanf("%d", &n);
    getchar(); // Remove o '\n' após o número de casos

    for (int i = 0; i < n; i++) {
        char entrada[301];
        fgets(entrada, 301, stdin);
        entrada[strcspn(entrada, "\n")] = '\0'; // Remove o '\n' de fgets

        int j = 0;
        while (entrada[j] != '\0') {
            if (entrada[j] >= 'a' && entrada[j] <= 'z' || entrada[j] >= 'A' && entrada[j] <= 'Z' || entrada[j] >= '0' && entrada[j] <= '9') {
                inserir(entrada[j], saida);
            } else if (entrada[j] == '(') {
                empilhar(entrada[j], cabeca);
            } else if (entrada[j] == ')') {
                while (cabeca->seg != NULL && cabeca->seg->num != '(') {
                    inserir(Desempilha(cabeca), saida);
                }
                if (cabeca->seg != NULL) {
                    Desempilha(cabeca); // Remove o '(' da pilha
                }
            } else {
                while (cabeca->seg != NULL && ordem(cabeca->seg->num) >= ordem(entrada[j])) {
                    inserir(Desempilha(cabeca), saida);
                }
                empilhar(entrada[j], cabeca);
            }
            j++;
        }

        // Após processar toda a entrada, esvazia a pilha de operadores
        while (cabeca->seg != NULL) {
            inserir(Desempilha(cabeca), saida);
        }

        // Imprime a expressão em pós-fixa na ordem correta
        imprimir_invertido(saida);

        // Limpa a lista de saída para o próximo caso de teste
        while (saida->seg != NULL) {
            Desempilha(saida);
        }
    }

    free(cabeca);
    free(saida);

    return 0;
}
