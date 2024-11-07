//Este código corresponde ao inicio da resolucao do exerccio 3160 do beecrowd, não está completo, mas é o inicio, começando a entender listas dinamicas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 15

struct cel{
    char name[maxSize];
    struct cel *seg;
};
typedef struct cel celula;

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


void Imprima (celula *lst) {
    celula *p;
    for (p = lst->seg; p != NULL; p = p->seg)
    printf ("%s\n", p->name);
}


celula *buscaAnterior(char x[],  celula *lst){
    celula *p;
    p = lst->seg;
    while (p != NULL && strcmp(p->name, x)==0){
        if(strcmp(p->name, x) != 0){
            p = p->seg;
        }else{
            return p;
        }
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
    
    return 0;
}
