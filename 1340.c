//Lucas Tosetti de Vasoncellos
//RA 176577

#include <stdio.h>
#include <stdlib.h>

struct cel {
    int num;    // conteúdo do nó
    struct cel *seg;    // ponteiro que aponta para o próximo nó
};
typedef struct cel celula;


void empilhar(int y, celula *p) {
    celula *nova = malloc(sizeof(celula));
    nova->num = y;
    nova->seg = p->seg;
    p->seg = nova;
}


int Desempilha(celula *p) {
    celula *q = p->seg;
    int x = q->num;
    p->seg = q->seg;
    free(q);
    return x;
}


void inserir_fila(int y, celula **inicio, celula **fim) {
    celula *nova = malloc(sizeof(celula));
    nova->num = y;
    nova->seg = NULL;
    if (*fim == NULL) {
        *inicio = *fim = nova;
    } else {
        (*fim)->seg = nova;
        *fim = nova;
    }
}


int remover_fila(celula **inicio, celula **fim) {
    celula *p = *inicio;
    int x = p->num;
    *inicio = p->seg;
    if (*inicio == NULL) *fim = NULL;
    free(p);
    return x;
}


void inserir_prioridade(int y, celula **inicio) {
    celula *nova = malloc(sizeof(celula));
    nova->num = y;
    nova->seg = NULL;

    celula *atual = *inicio;
    celula *anterior = NULL;

    while (atual != NULL && atual->num > y) {
        anterior = atual;
        atual = atual->seg;
    }

    if (anterior == NULL) {
        nova->seg = *inicio;
        *inicio = nova;
    } else {
        nova->seg = anterior->seg;
        anterior->seg = nova;
    }
}

int remover_prioridade(celula **inicio) {
    celula *p = *inicio;
    int x = p->num;
    *inicio = p->seg;
    free(p);
    return x;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        celula *pilha = malloc(sizeof(celula));
        pilha->seg = NULL;

        celula *fila_inicio = NULL, *fila_fim = NULL;
        celula *fila_prioridade = NULL;

        int is_stack = 1, is_queue = 1, is_priority_queue = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d", &x);
                empilhar(x, pilha);
                inserir_fila(x, &fila_inicio, &fila_fim);
                inserir_prioridade(x, &fila_prioridade);
            } else {
                int removed;
                scanf("%d", &removed);

                if (is_stack) {
                    if (pilha->seg == NULL) {
                        is_stack = 0;
                    } else {
                        int stack_removed = Desempilha(pilha);
                        if (stack_removed != removed) is_stack = 0;
                    }
                }

                if (is_queue) {
                    if (fila_inicio == NULL) {
                        is_queue = 0;
                    } else {
                        int queue_removed = remover_fila(&fila_inicio, &fila_fim);
                        if (queue_removed != removed) is_queue = 0;
                    }
                }

                if (is_priority_queue) {
                    if (fila_prioridade == NULL) {
                        is_priority_queue = 0;
                    } else {
                        int priority_queue_removed = remover_prioridade(&fila_prioridade);
                        if (priority_queue_removed != removed) is_priority_queue = 0;
                    }
                }
            }
        }

        if (is_stack + is_queue + is_priority_queue > 1) {
            printf("not sure\n");
        } else if (is_stack) {
            printf("stack\n");
        } else if (is_queue) {
            printf("queue\n");
        } else if (is_priority_queue) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }


        while (pilha->seg != NULL) Desempilha(pilha);
        free(pilha);

        while (fila_inicio != NULL) remover_fila(&fila_inicio, &fila_fim);

        while (fila_prioridade != NULL) remover_prioridade(&fila_prioridade);
    }

    return 0;
}
