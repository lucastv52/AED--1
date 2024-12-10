int separar (int esq, int dir, int v[]) {
    int c, j, k, t;
    c = v[dir]; j = esq;
    for (k = esq; /*A*/ k < dir; k++)
        if (v[k] <= c) {
        t = v[j]
        v[j] = v[k]
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
