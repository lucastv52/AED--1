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

void inserir(char y[], celula *p, int size){
    celula *nova;
    nova = malloc(sizeof(celula));
    for (int i=0; i<size; i++) {
        nova->name[i] = y[i];
    }
    nova->seg = p->seg;
    p->seg = nova;
}


void Imprima (celula *lst) {
    celula *p;
    for (p = lst; p != NULL; p = p->seg)
    printf ("%s\n", p->name);
}


int main(){
    celula *amigo1 = malloc(sizeof(celula));
    celula *amigo2 = malloc(sizeof(celula));
    strcpy(amigo1->name,"lucas");
    strcpy(amigo2->name, "joao");
    amigo1->seg = amigo2;
    amigo2->seg = NULL;
    
    
    return 0;
}
