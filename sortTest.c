#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 400000; //constante para tamanho do vetor

void inserionSort(int v[], int n){
    int i, j, termoEsquerda;
    for (j = 1;  j < n; j++) {
        termoEsquerda = v[j];
        for (i = j-1; i >= 0 && v[i] > termoEsquerda; i--)
            v[i+1] = v[i];
        v[i+1] = termoEsquerda;
    }   
}

void intercalar(int esq, int meio, int dir, int v[]) {
    int i, j, k, *w;
    w = malloc ((dir-esq) * sizeof (int));
    i = esq; j = meio; k = 0;
    while (i < meio && j < dir) {
        if (v[i] <= v[j]){
            w[k++] = v[i++];
        }else{
            w[k++] = v[j++];
        }    
    }
    while (i < meio)
        w[k++] = v[i++];
    while (j < dir)
        w[k++] = v[j++];
    for (i = esq; i < dir; i++)
        v[i] = w[i-esq];
    free (w);
}
void mergeSort (int v[],int esq, int dir ) {
    if (esq < dir - 1) {
        int meio = (esq + dir)/2;
        mergeSort (v, esq, meio);
        mergeSort (v,meio, dir);
        intercalar (esq, meio, dir, v);
    }
}

int separar (int esq, int dir, int v[]) {
    int c, j, k, t;
    c = v[dir]; j = esq;
    for (k = esq; /*A*/ k < dir; k++)
        if (v[k] <= c) {
        t = v[j];
        v[j] = v[k];
        v[k] = t;
        j++;
        }
    v[dir] = v[j], v[j] = c;
    return j;
    }

void quicksort (int esq, int dir, int v[]) {
    int j;
    if (esq < dir) {
        j = separar (esq, dir, v);
        quicksort (esq, j - 1, v);
        quicksort (j + 1, dir, v);
    }
}


int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    int i, j, tam;
    tam = 20000;
    for(i = 0; i<20; i++){
        for(int a = 0; a < tam; a++)
            vetor[a] = rand() % tam;    
        
        t = clock(); //armazena tempo
        quicksort(0, tam, vetor);
        t = clock() - t; //tempo final - tempo 
        
        printf("%d ", tam);
        printf("Tempo de execucao: %lf s\n", (((double)t)/((CLOCKS_PER_SEC/1000))/1000)); //conversão para double
        tam += 20000;
    }
    
    

    return 0;
}

