//Lucas Tosetti de Vasoncellos RA: 176577

#include <stdio.h>
#include <math.h>


int main(){
    int t, a, b, c;
    double yv, delta;
    scanf("%d", &t);
    for(int i = 0; i<t; i++){
        scanf("%d %d %d", &a, &b, &c);
        delta = b*b - (4*a*c);
        yv = (-delta)/ (4*a);
        printf("%.2lf\n", yv);
    }
    return 0;
}
