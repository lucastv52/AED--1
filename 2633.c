#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel {
    char carne[51];
    int data;
} item;

void swap(item *a, item *b) {
    item temp = *a;
    *a = *b;
    *b = temp;
}


int partition(item arr[], int low, int high) {
    int pivot = arr[high].data; 
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        
        if (arr[j].data < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return i + 1; 
}


void quicksort(item arr[], int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);      
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


void printItens(item arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s", arr[i].carne);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        item lista[n];
        for (int i = 0; i < n; i++) {
            char entrada[51];
            int dia;
            scanf("%s %d", entrada, &dia);
            strcpy(lista[i].carne, entrada);
            lista[i].data = dia;
        }
        quicksort(lista, 0, n - 1); 
        printItens(lista, n);
    }

    return 0;
}
