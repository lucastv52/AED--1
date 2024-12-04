#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 200000; //constante para tamanho do vetor

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


int main(){
    clock_t t; //variável para armazenar tempo
    int vetor[TAM];
    
    //semente de aleatoriedade
    srand((unsigned)time(NULL));

    //geração aleatório dos valores do vetor
    for(int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    //Verificando tempo de execução do bubble sort=> t2
    t = clock(); //armazena tempo
    inserionSort(vetor, TAM);
    t = clock() - t; //tempo final - tempo 

    //imprime o tempo na tela
    printf("%d\n", TAM);
    printf("Tempo de execucao: %lf s\n", (((double)t)/((CLOCKS_PER_SEC/1000)))); //conversão para double

    return 0;
}

