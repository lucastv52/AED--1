//Esse código tem como objetivo resolver o exercicio 2460 do beecrowd

#include <stdio.h>
#include <stdlib.h>

struct cel{
    int num;
    struct cel *seg;
};
typedef struct cel celula;

void inserir(int y, celula *p){    
    celula *nova;
    nova = malloc(sizeof(celula));   
    nova->num = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void Imprima (celula *lst) {
    celula *p;
    for (p = lst->seg; p != NULL; p = p->seg){
        if(p->seg == NULL)
            printf ("%d\n", p->num);
        else    
            printf ("%d ", p->num);
    }
    
}

void BuscaERemove (int x, celula *lst) {
    celula *p, *q;
    p = lst;
    q = lst->seg;
    while (q != NULL && q->num != x) {
        p = q;
        q = q->seg;
    }
    if (q != NULL) {
        p->seg = q->seg;
        free (q);
    }
}

int main(){
    // declaração da cabeça da lista
    celula *cabeca = malloc(sizeof(celula));    
    cabeca->seg = NULL;

    //numero de elementos da fila
    int n;
    scanf("%d",&n);

    //Loop para criar a lista de N elementos
    int lista;
    celula *prox = cabeca;
    for(int i =0; i<n;i++){
        scanf("%d",&lista);
        inserir(lista, prox);
        prox = prox->seg;
    }
    
    //numero de elementos que serão removidos
    int m;
    scanf("%d",&m);

    //loop para receber a entrada, e remover os elementos indesejados
    int removidos;
    for(int i = 0; i<m; i++){
        scanf("%d", &removidos);
        BuscaERemove(removidos, cabeca);
    }
    Imprima(cabeca);

    return 0;
}
