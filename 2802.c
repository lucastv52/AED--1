#include <stdio.h>

long long calcular_regioes(int N) {
    if (N == 1) return 1;
    if (N == 2) return 2;
    if (N == 3) return 4;
    if (N == 4) return 8;
    
   
    long long C2 = (long long)N * (N - 1) / 2;
    long long C4 = (long long)N * (N - 1) * (N - 2) * (N - 3) / 24;
    return 1 + C2 + C4;
}

int main() {
    int N;
    
    
    scanf("%d", &N);
    
    printf("%lld\n", calcular_regioes(N));
    
    return 0;
}
