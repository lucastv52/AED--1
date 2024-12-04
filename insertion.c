#include <stdio.h>
#include <stdlib.h>

void inserionSort(int v[], int n){
    int i, j, termoEsquerda;
    for (j = 1;  j < n; j++) {
        termoEsquerda = v[j];
        for (i = j-1; i >= 0 && v[i] > termoEsquerda; i--)
            v[i+1] = v[i];
        v[i+1] = termoEsquerda;
    }   
}


int main(){
    int vetor[10] = {1,6,7,4,1,0,-5,6,8,3};
    for(int i = 0; i<10; i++)
        printf("%d ", vetor[i]);
    printf("\n");    
    inserionSort(vetor, 10);
    for(int i = 0; i<10; i++)
        printf("%d ", vetor[i]);
    return 0;
}
