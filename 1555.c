#include <stdio.h>
#include <math.h>
int beto(int x, int y){
    return (2 * x *x )+ ((5*y) * (5*y));
}
int rafael(int x, int y){
    return (3*x) * (3*x) = (y*y);
}
int carlos(int x, int y){
    return -100*x + y*y*y;
}

int main(){
    int n, x,y;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d %d", &x, &y);
        if(beto(x,y) > rafael(x,y) && beto(x,y)> carlos(x,y))
            printf("Beto ganhou\n");
        else if(rafael(x,y)> beto(x,y) &&rafael(x,y)> carlos(x,y) )
            printf("Rafael ganhou\n");
        else if(carlos(x,y) > beto(x,y) && carlos(x,y) > rafael(x,y))
            printf("Carlos ganhou\n");
    }
    return 0;
}
