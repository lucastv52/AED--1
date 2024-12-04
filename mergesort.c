#include <stdio.h>
#include <stdlib.h>

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
    int vetor[10] = {1,6,7,4,1,0,-5,6,8,3};
    for(int i = 0; i<10; i++)
        printf("%d ", vetor[i]);
    printf("\n");    
    mergeSort(vetor, 0, 10);
    for(int i = 0; i<10; i++)
        printf("%d ", vetor[i]);

    return 0;
}
