#include <stdio.h>

int main(){
    int t, v, deslocamento;

    while(scanf("%d %d", &v, &t) != EOF){
        deslocamento = v*t*2;
        printf("%d\n", deslocamento);

    }

    return 0;
}
