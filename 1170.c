//Lucas Tosetti de Vasconcellos RA 176577

#include <stdio.h>

int main(){
    int n;
    float c;
    scanf("%d", &n);
    for(int i =0 ; i<n ; i++){
        scanf("%f", &c);
        int count = 0;
        while(c > 1){
            c /= 2;
            count ++;            
        }
        printf("%d dias\n", count );
    }


    return 0;
}
