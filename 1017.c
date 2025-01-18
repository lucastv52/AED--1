#include <stdio.h>

int main(){
    int tempo, velocidade;
    float dist, gas;

    scanf("%d %d", &tempo, &velocidade);

    dist = velocidade *tempo;
    gas = dist/12.0;

    printf("%.3f\n", gas);

    return 0;
}
