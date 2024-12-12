#include <stdio.h>

void pilhaVetor(){
    //Filas são estruturas de dados que seguem um padrão, o ultimo elemento a entrar, será o primeiro elemento a sair (LIFO)
    //em vetores:
    int pilha[50], valor, x;
    //haverá também um T que aponta para o elemento da pilha q será retirado
    int t = 0; // quando t = 0 a pilha está vazia;
    // para empilhar, fazemos:
    pilha[t++] = valor;
    //para desempilhar:
    x = pilha[t--];
}
//Implementação em lista encadeada:
struct cel{
    int num;    //conteudo do nó
    struct cel *seg;    // ponteiro que aponta para o próximo né
};
typedef struct cel celula;

//Como a lista tem cabeça, o topo da pilha está na segunda célula:

int main(){
    celula *cabeca = malloc(sizeof(celula));
    celula *p = &cabeca;
}
//para empilhar:
void empilhar (int y, celula *p) { //insere uma celula de valor Y após a cabeca;
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->num = y;
    nova->seg = p->seg;
    p->seg = nova;
}

//para desempilhar:
int Desempilha (celula *p) {
    int x; celula *q;
    q = p->seg;
    x = q->num;
    p->seg = q->seg;
    free (q);
    return x;
}