#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel {
    int termo;
    struct cel *seg;
};

typedef struct cel celula;

void inserir(int y, celula *p){
    
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->termo = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void remove(celula *p) {
    if (p->seg != NULL) {
        celula *lixo = p->seg;
        p->seg = lixo->seg;
        free(lixo);
    }
}
int buscaMin(celula *p){
    int min;
    while(p->seg != NULL){
        //FINALIZAR FUNÇÃO
    }
}


int main(){
    celula *cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;
    cabeca->termo = 'j';

    int n, min;
    scanf("%d", &n);

    for(int i =0; i<n;i++){
        char entrada[10];
        int num;
        scanf("%s %d", &entrada, &num);
        if(strcmp(entrada, "PUSH")){
            inserir(num, cabeca);
            if(cabeca->seg == NULL) min = num;
            else{
                if(num<min) min = num;
            }
        }else if(strcmp(entrada, "POP")){
            if(cabeca->seg == min){
                // min == buscaMin(cabeca)
            }
            remove(cabeca->seg);
        }else if(strcmp(entrada, "MIN")){
            //fazer código para devolver o menor valor
            printf("%d",min);
        }
    }

    return 0;
}
