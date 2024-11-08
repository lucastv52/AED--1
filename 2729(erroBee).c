#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 15



struct cel{
    char name[maxSize];
    struct cel *seg;
};
typedef struct cel celula;
void inserirFinal(char y[], celula *p) {
    celula *nova = malloc(sizeof(celula));
    strcpy(nova->name, y);
    nova->seg = NULL;

    // Percorre até o final da lista para inserir o novo elemento
    while (p->seg != NULL) {
        p = p->seg;
    }
    p->seg = nova;
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
            printf ("%s", p->name);
        else    
            printf ("%s ", p->name);
    }
    printf("\n");
}
int in(char palavra[], celula *lst){
    celula *p;
    for(p = lst->seg; p !=NULL; p = p->seg){
        if(strcmp(palavra, p->name)==0)
            return 1;      
    }
    return 0;
}

celula *Busca (char x[15], celula *lst) {
    celula *p;
    p = lst->seg;
    while (p != NULL && strcmp(p->name,x)!=0)
        p = p->seg;
    return p;
}

int main(){
    fflush(stdin);
    celula *cabeca = malloc(sizeof(celula));
    strcpy(cabeca->name,"cabeca");
    cabeca->seg = NULL;

    int n;
    char entrada[150];
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
