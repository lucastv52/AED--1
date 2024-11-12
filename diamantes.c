//Lucas Tosetti de Vasconcellos RA 176577

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct cel {
    char termo;
    struct cel *seg;
};

typedef struct cel celula;



void inserir(char y, celula *p){
    
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->termo = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void Remove(celula *p) {
    if (p->seg != NULL) {
        celula *lixo = p->seg;
        p->seg = lixo->seg;
        free(lixo);
    }
}

void limpa_pilha(celula *p) {
    while (p->seg != NULL) {
        Remove(p);
    }
}

int main(){
    celula *cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;
    cabeca->termo = 'j';

    int n, diamantes;
    
    scanf("%d", &n);
    getchar();

    char entrada[1000];
    for(int i = 0; i<n;i++){
        fgets(entrada, sizeof(entrada),stdin);
        diamantes = 0;
        celula *atual;

        for(int j = 0; entrada[j] != '\0'; j++){
            atual = cabeca->seg;
            if(entrada[j] == '<'){
                inserir(entrada[j], cabeca);
            }else if(entrada[j] == '>'){
                if(cabeca->seg != NULL && cabeca->seg->termo == '<'){
                    diamantes++;
                    Remove(cabeca);
                }
            }           
        }
        printf("%d\n", diamantes);         
    }
    return 0;
}
