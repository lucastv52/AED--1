void inserionSort(int v[], int n){
    int i, j, termoEsquerda;
    for (j = 1;  j < n; j++) {
        termoEsquerda = v[j];
        for (i = j-1; i >= 0 && v[i] >= termoEsquerda; i--)
            v[i+1] = v[i];
        v[i+1] = termoEsquerda;
    }   
}

void Seleção (int n, int v[]) {
    int i, j, min, x;
    for (i = 0;  i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
        if (v[j] < v[min]) min = j;
        x = v[i];
        v[i] = v[min]; 
        v[min] = x;
    }
}