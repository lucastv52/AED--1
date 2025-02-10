#include <stdio.h>

int main(){
    int t, count, n, idade;
    scanf("%d",&t);
    for(int i = 0; i<t; i++){
        count = 0;
        scanf("%d", &n);
        int time[n+1];
        for(int j = 0; j<n; j++){
            scanf("%d", &idade);
            time[j+1] = idade;
        }
        printf("Case %d: %d\n", i+1, time[(n/2)+1]);
    }


    return 0;
}
