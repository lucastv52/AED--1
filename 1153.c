#include <stdio.h>

int main(){
    int n, final;
    final = 1;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        final *= i;
    }
    printf("%d\n", final);
    return 0;
}
