#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 20001



struct cel{
    //declaração do tipo da célula
    char name[maxSize];
    struct cel *seg;
};
typedef struct cel celula;
void inserirFinal(char y[], celula *p) {
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->name, y);
    nova->seg = NULL;
    //percorre a lista até o último termo e depois insere um novo
    while (p->seg != NULL) {
        p = p->seg;
    }
    p->seg = nova;
}
void Ordenar(celula *lst) {
    //ordena a lista em ordem alfabética, usando comparação de strings
    for (celula *i = lst->seg; i != NULL; i = i->seg) {
        for (celula *j = i->seg; j != NULL; j = j->seg) {
            if (strcmp(i->name, j->name) > 0) {
                char temp[maxSize];
                strcpy(temp, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp);
            }
        }
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

void Imprima (celula *lst) {
    celula *p;
    for (p = lst->seg; p != NULL; p = p->seg){
        if(p->seg == NULL)
            printf ("%s\n", p->name);
        else    
            printf ("%s ", p->name);
    }
    
}
int in(char palavra[], celula *lst){
    celula *p;
    for(p = lst->seg; p !=NULL; p = p->seg){
        if(strcmp(palavra, p->name)==0)
            return 1;      
    }
    return 0;
}

celula *Busca (char x[], celula *lst) {
    celula *p;
    p = lst->seg;
    while (p != NULL && strcmp(p->name,x)!=0)
        p = p->seg;
    return p;
}

int main(){
    celula *cabeca = malloc(sizeof(celula));
    strcpy(cabeca->name,"cabeca");
    cabeca->seg = NULL;

    int n;
    char entrada[20001];
    scanf("%d", &n);
    char *item;

    for(int i = 0; i<=n;i++){
        gets(entrada);
        item = strtok(entrada, " ");
        celula *prox = cabeca;
        while(item !=NULL){
            if(in(item,prox) == 0){       
                inserirFinal(item, cabeca);                               
            }
            item = strtok(NULL, " ");   
        }
        Ordenar(cabeca);
        Imprima(cabeca); 
        
        celula *temp;
        while (cabeca->seg != NULL) {
            temp = cabeca->seg;
            cabeca->seg = temp->seg;
            free(temp);
        }
    }
    
    free(cabeca);  
    return 0;
}
