//Lucas Tosetti de Vasconcellos RA 176577
//Este código corresponde a resolução do exercicio 2929 do beecrowd

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

void remover(celula *p) {
    if (p->seg != NULL) {
        celula *lixo = p->seg;
        p->seg = lixo->seg;
        free(lixo);
    }
}

int main(){
    celula *cabeca = malloc(sizeof(celula));
    cabeca->seg = NULL;

    celula *menores = malloc(sizeof(celula));
    menores->seg = NULL;

    int n;
    scanf("%d", &n);

    for(int i =0; i<n;i++){
        char entrada[10];
        int num;
        scanf("%s", entrada);
        getchar();

        if(strcmp(entrada, "PUSH") == 0){
            scanf("%d", &num);
            inserir(num, cabeca);
            if(menores->seg == NULL || num <= (menores->seg)->termo ){
                inserir(num, menores);
            }
        }else if(strcmp(entrada, "POP") == 0){
            if (cabeca->seg == NULL) {
                printf("EMPTY\n");
            } else {
            if ((cabeca->seg)->termo == (menores->seg)->termo) {
                remover(menores);
            }
            remover(cabeca);
            }
        }else if(strcmp(entrada, "MIN") == 0){
            if(menores->seg != NULL) printf("%d\n", (menores->seg)->termo);
            else printf("EMPTY\n");
        }
    }


    return 0;
}
