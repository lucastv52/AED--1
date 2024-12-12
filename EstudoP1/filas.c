#include <stdio.h>
#include <stdlib.h>


int filas(){
    //Filas são estruturas de dados que seguem um padrão, o primeiro elemento a entrar, será o primeiro elemento a sair (FIFO)
    //Implementação das filas em vetores:
    int fila[50], y, x;
    int N; // tamanho do vetor
    //além do vetor, terão dois parâmetros que mostram o início e final da fila, inicialmente, ambos são 0;
    int t, s = 0;
    //implementando uma fila circular, para remover um termo, usa-se:
    fila[t++] = y;
    if(t == N) t = 0;
    // para remover:
    x = fila[s++];
    if(s == N) s = 0;
    return 0;
}

void filasEncadeadas(){
    

    // Neste caso, também haverão dois ponteiros que apontam para o inicio e o final da fila: s e t, respetivamente
    //S é onde sai, T é onde entra
    celula *s, *t;
    s = t = NULL;

}

//Implementação em lista encadeada:
//declaração do tipo célula
struct cel{
    int num;    //conteudo do nó
    struct cel *seg;    // ponteiro que aponta para o próximo né
};
typedef struct cel celula;

// para remover um termo
int remover(celula **ss, celula **tt){
    celula *p = *ss;
    int x;
    x = p->num;
    *ss = p->seg;
    free(p);
    if(*ss = NULL) *tt = NULL;
    return x;
}

//para inserir um termo:
void inserir(int y,celula **ss, celula **tt ){
    celula *nova = malloc(sizeof(celula));
    nova->num = y;
    nova->seg = NULL;
    if(*tt = NULL) *tt = *ss = nova;
    else{
        (*tt)->seg = nova;
        *tt = nova;
    }
}