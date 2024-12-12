#include <stdio.h>

//As arvores são listas encadeadas porém cada nó tem 2 filhos, sendo que o filho da direita sempre será maior que o pai, e o filho da esquerda menor.

//declarando o tipo do nó de arvore:

struct cel {
    int num;
    struct cel *esq;
    struct cel *dir;
};
typedef struct cel no;
typedef no *arvore;


// para printar uma árvore em forma crescente, usa-se um algortimo recursivo que varre ela no modelo esquerda-raiz-direita
void printArv(arvore tronco){
    if(tronco != NULL){
        printArv(tronco->esq);          //percorre recusivamente até o ultimo termo da esquerda (menor), e volta printando todos
        printf("%d\n", tronco->num);
        printArv(tronco->dir);
    }
}
//para fazer uma busca em árvore binária:
no *Busca (arvore r, int k) {
    if (r == NULL || r->num == k)
        return r;
    if (r->num > k)
        return Busca (r->esq, k);
    else
        return Busca (r->dir, k);
}
int main(){
    return 0;
}