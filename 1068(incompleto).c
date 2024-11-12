// exercicio 1068 do beecrowd, pilha e parênteses

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

void Remove (celula *p) {
    celula *lixo;
    lixo = p->seg;
    p->seg = lixo->seg;
    free (lixo);
}

void limpa_pilha(celula *p) {
    while (p->seg != NULL) {
        Remove(p);
    }
}

int main(){
    int loop = 1;
    celula *cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;

    char entrada[100];
    while(loop ==1){
        gets(entrada);
        int correto =1;
        for(int i=0; entrada[i] != '\0';i ++ ){
            celula *atual = cabeca->seg;
            if(entrada[i] == '('){
                inserir(entrada[i],cabeca);
            }else if(entrada[i] == ')'){
                if(cabeca->seg != NULL && cabeca->seg->termo == '('){
                    Remove(cabeca);
                }else{
                    correto =0;
                    break;
                }
            }
        }
        if(correto ==1){
            printf("correct\n");                 
        }else{
            printf("incorrect\n");
        }
        limpa_pilha(cabeca);
    }
    free(cabeca);
    return 0;
}
