//Este código corresponde ao exercicio 3160 do beecrowd, ele tem como função utilizar uma lista encadeada para criar uma lista de amigos.
//Lucas Tosetti de Vasconcellos RA 176577
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 15

struct cel{
    char name[maxSize];
    struct cel *seg;
};
typedef struct cel celula;

celula *buscarAnterior(celula *lst, char valor[15]) {
    // Verifica se a lista está vazia ou se o primeiro nó é o valor desejado
    if (lst == NULL || lst->seg == NULL) {
        return NULL;
    }

    celula *atual = lst;

    // Percorre a lista até que o próximo nó seja o desejado
    while (atual->seg != NULL && strcmp(atual->seg->name,valor) != 0) { 
        atual = atual->seg;
    }

    // Retorna o nó anterior se encontrar, caso contrário NULL
    if (atual->seg != NULL && strcmp(atual->seg->name,valor) == 0) {
        return atual;
    } else {
        return NULL;
    }
}





void inserir(char y[], celula *p){
    int size = strlen(y);
    celula *nova;
    nova = malloc(sizeof(celula));
    for (int i=0; i<size; i++) {
        nova->name[i] = y[i];
    }
    nova->name[size] = '\0';
    nova->seg = p->seg;
    p->seg = nova;
}
void inserirDepois(char y[], celula *p){
    int size = strlen(y);
    celula *nova;
    nova = malloc(sizeof(celula));
    for (int i=0; i<size; i++) {
        nova->name[i] = y[i];
    }
    nova->name[size] = '\0';
    nova->seg = p->seg;
    p->seg = nova;
}

void Imprima (celula *lst) {
    celula *p;
    for (p = lst->seg; p != NULL; p = p->seg){
        if(p->seg == NULL)
            printf ("%s", p->name);
        else    
            printf ("%s ", p->name);
    }
}


celula *Busca (char x[15], celula *lst) {
    celula *p;
    p = lst->seg;
    while (p != NULL && strcmp(p->name,x)!=0)
        p = p->seg;
    return p;
}


celula *buscaUltimo(celula *lst){
    celula *p;
    p = lst->seg;
    while (p->seg != NULL) {
        p = p->seg;
    }
    return p;
}


int main(){
    //inicializando cabeça da lista
    celula *cabeca = malloc(sizeof(celula));
    strcpy(cabeca->name,"teste");
    cabeca->seg = NULL;
    
    char *nome;
    char entrada[128];
    gets(entrada);

    nome = strtok(entrada, " ");
    celula *prox = cabeca;
    while(nome !=NULL){
        inserir(nome, prox);
        nome = strtok(NULL, " ");
        prox = prox->seg;
    }
    char entrada2[128];
    gets(entrada2);
    
    char entrada3[10];
    scanf("%s", &entrada3);
    

    if(strcmp(entrada3, "nao") !=0 ){
        celula *anterior = buscarAnterior(cabeca, entrada3);
        nome = strtok(entrada2, " ");
        while(nome !=NULL){
            inserir(nome, anterior);
            nome = strtok(NULL, " ");
            anterior = anterior->seg;
        }
    }else{
        celula *ultimo = buscaUltimo(cabeca);
        nome = strtok(entrada2, " ");
        while(nome !=NULL){
            inserir(nome, ultimo);
            nome = strtok(NULL, " ");
            ultimo = ultimo->seg;
        }
    }
    Imprima(cabeca);
    printf("\n");
    return 0;
}
