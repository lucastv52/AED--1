#include <stdio.h>

int main(){
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    getchar();

    char matriz[linha][coluna];
    char entrada;
    for(int i = 0; i<linha; i++){
        for(int j = 0; j<coluna; j++){
            scanf("%c", &entrada);
            matriz[i][j] = entrada;
        }
    }
    // for(int i = 0; i<linha; i++){
    //     for(int j = 0; j<coluna; j++){
    //         printf("%c", matriz[i][j]);
    //     }
    // }

    return 0;
}
