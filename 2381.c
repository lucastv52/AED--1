#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxSize 21

struct cel{
    char name[maxSize];
    struct cel *seg;
};
typedef struct cel celula;

void inserir(char y[], celula *p){
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->name, y);
    nova->seg = p->seg;
    p->seg = nova;
}

void imprimir(celula *p){
    celula *atual;
    for(atual = p->seg; atual != NULL; atual = atual->seg){
        if(atual->seg == NULL)
            printf("%s\n", atual->name);
        else
            printf("%s ", atual->name);
        
    }
}
void ordenar(celula *p){
    celula *atual, *proximo;
    char aux[21];
    for(atual = p->seg; atual != NULL; atual = atual->seg){
        for(proximo = atual->seg; proximo != NULL; proximo = proximo->seg){
            if(strcmp(atual->name, proximo->name)>0){
                strcpy(aux, atual->name);
                strcpy(atual->name, proximo->name);
                strcpy(proximo->name, aux);
            }
            
        }
    }
}


int main(){
    celula *cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;

    int n, k;
    scanf("%d %d", &n, &k);
    getchar();

    char entrada[21];

    for(int i = 0; i<n; i++){
        gets(entrada);
        inserir(entrada, cabeca);
    }
    ordenar(cabeca);
    
    celula *atual = cabeca;
    for(int i = 0; i<=k; i++){
        if(i == k)
            printf("%s\n", atual->name);
        else
            atual = atual->seg;
    }
    free(atual);
    
    return 0;
}
