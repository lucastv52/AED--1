#include <stdio.h>

//Listas encadeadas:
    //declaração do tipo célula
struct cel{
    int num;    //conteudo do nó
    struct cel *seg;    // ponteiro que aponta para o próximo né
};
typedef struct cel celula;

//Para criar uma célula com cabeça, fazemos
/* celula *cabeca = malloc(sizeof(celula))*/

//Para printar uma lista:

void imprimir(celula *lista){
    celula *p;
    p = lista;
    for(p = lista; p != NULL; p = p->seg ) // percorre a lista toda até a ultima célula
        printf("%d", p->num);
}

//Para buscar em uma lista encadeada:
celula *Busca(int x, celula *lista){
    celula *p = lista->seg;
    while(p != NULL && p->num != x) // procura toda a lista até o termo ser == x
        p = p->seg; //incrementa a procura
    return p;    
}

//Para remover uma célula:

void remover(celula *p){ //remove a célula seguinte a P
    celula *x = p->seg;
    p->seg = x->seg; //modifica os ponteiros e libera a célula descartada
    free(x);
}

//para inserir uma célula:
void inserir(int valor, celula *p){ //cria uma nova celula apos a celula P
    celula *nova = malloc(sizeof(celula));
    nova->num = valor;
    nova->seg = p->seg; //manipula os ponteiros
    p->seg = nova;
}

//para buscar e remover ou inserir:
void buscarEremover(int x, celula *lista){
    celula *p, *q;
    p = lista;
    q = lista->seg; // cria dois ponteiros que apontam para celulas seguintes
    while (q != NULL && q->num != x) { //verifica se a celula da frente é == x
        p = q;
        q = q->seg;  // caso nao for, continua percorrendo
    }
    if (q != NULL) {
        p->seg = q->seg; // se que existir, libera ela
        free (q);
    }
    
}

void buscarEinserir(int x, int y, celula *lista){
    celula *p, *q, *nova;
    nova = malloc (sizeof (celula)); // cria a celula nova com conteudo y
    p = lista;
    q = lista->seg;
    while (q != NULL && q->num != x) {  //percorre toda lista até encontrar x
        p = q;
        q = q->seg;
    }
    nova->seg = q; // manipula os ponteiros para manter a ordem certa
    p->seg = nova;
    }