#include <stdio.h>
#include <math.h>

int primo(int y){    
    for(int i = 2; i<sqrt(y);i++){
        if(y%i == 0){
            return 0;
        }
    }
    return 1;
}


int main(){
    int vezes, num;
    scanf("%d", &vezes);
    for(int i = 0; i<vezes;i++){
        scanf("%d", &num);
        if(num == 1 || num == 2 ){
            printf("Prime\n");
        }else if(num%2 ==0){
            printf("Not Prime\n");
        }else if(primo(num) == 0){
            printf("Not Prime\n");
        }else{
            printf("Prime\n");
        }
    }
    
    return 0;

}
