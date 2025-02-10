//Lucas Tosetti de Vasconcellos RA 176577

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
    char aviao[1001];
    struct cel *seg;
};
typedef struct cel celula;

void inserirFim(char valor[1001], celula **head) {
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->aviao, valor);
    nova->seg = NULL;

    if (*head == NULL) {
        *head = nova;
    } else {
        celula *p = *head;
        while (p->seg != NULL)
            p = p->seg;
        p->seg = nova;
    }
}

void imprimir_alternado(celula *lista1, celula *lista2, celula *lista3, celula *lista4) {
    celula *p1 = lista1;  
    celula *p2 = lista2;  
    celula *p3 = lista3; 
    celula *p4 = lista4;  

    int primeiro = 1;  


    while (p1 != NULL || p2 != NULL || p3 != NULL || p4 != NULL) {
  
        if (p1 != NULL) {
            if (!primeiro) printf(" ");
            printf("%s", p1->aviao);
            p1 = p1->seg;
            primeiro = 0;
        }

   
        if (p2 != NULL) {
            if (!primeiro) printf(" ");
            printf("%s", p2->aviao);
            p2 = p2->seg;
            primeiro = 0;
        }


        if (p3 != NULL) {
            if (!primeiro) printf(" ");
            printf("%s", p3->aviao);
            p3 = p3->seg;
            primeiro = 0;
        }


        if (p4 != NULL) {
            if (!primeiro) printf(" ");
            printf("%s", p4->aviao);
            p4 = p4->seg;
            primeiro = 0;
        }
    }
    printf("\n");  
}

int main() {
    celula *norte = NULL;
    celula *sul = NULL;
    celula *leste = NULL;
    celula *oeste = NULL;

    char entrada[1001];
    int ponto;

    while (1) {
        scanf("%d", &ponto);
        if (ponto == 0) {
            break;  
        }

        scanf("%s", entrada);

        switch (ponto) {
            case -1:
                inserirFim(entrada, &oeste);
                break;
            case -2:
                inserirFim(entrada, &sul);
                break;
            case -3:
                inserirFim(entrada, &norte);
                break;
            case -4:
                inserirFim(entrada, &leste);
                break;
            default:
                printf("Ponto cardeal inválido.\n");
                break;
        }
    }

    imprimir_alternado(oeste, norte, sul, leste);

  

    return 0;
}
