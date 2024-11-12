// exercicio 1068 do beecrowd, pilha e parênteses
//Lucas Tosetti de Vasconcellos RA:176577
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
    
    celula *cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;

    char entrada[1000];
    while(fgets(entrada, sizeof(entrada), stdin)!=NULL){
        
        int correto =1;
        for(int i=0; entrada[i] != '\0';i ++ ){
            celula *atual = cabeca->seg;
            if(entrada[i] == '('){
                inserir(entrada[i],cabeca);
            }else if(entrada[i] == ')'){
                if(cabeca->seg != NULL && (atual->termo == '(')){
                    Remove(cabeca);
                }else{
                    correto =0;
                    break;
                }
            }
        }
        if(correto && cabeca->seg ==NULL){
            printf("correct\n");                 
        }else{
            printf("incorrect\n");
        }
        limpa_pilha(cabeca);
    }
    free(cabeca);
    return 0;
}
