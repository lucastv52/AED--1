#include <stdio.h>

//O o heap é uma estrutura de dados que simula uma arvore binária em um vetor:
//no qual o indíce 1 é a raiz, o 2 e 3 são seus filhos
//ele segue a regra: 
// p é o pai
// 2p é o filho esquerdo
//2p+1 é o filho direito
// existe o max-heap e o min-heap,
//no max heap o valor do pai é sempre maior que o valor dos filhos, deste modo, o indice 1 tem sempre o maior valor do vetor;
int main(){
    
    return 0;
}
//para inserir:
void InsereEmHeap (int m, int v[]) { //recebe um heap que vai até M, e coloca o elemento M+1 no heap também, em sua devida posição
    int f = m+1;
    while (f > 1 && v[f/2] < v[f]) {
        int t = v[f/2]; 
        v[f/2] = v[f]; 
        v[f] = t;
        f = f/2;
    }
}

//para remover:
//receberá um vetor com um elemento do heap removido, e o "sacodirá" para transformá-lo num heap novamente:
void SacodeHeap (int m, int v[]) {
    int t, f = 2;
    while (f <= m) {
        if (f < m && v[f] < v[f+1]) ++f;
        if (v[f/2] >= v[f]) break;
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f *= 2;
    }
}
