#include <stdio.h>

int main(){
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);
    getchar();

    char matriz[linha][coluna];
    char entrada;
    for(int i = 0; i<linha; i++){
        for(int j = 0; j<coluna; j++){
            scanf(" %c", &entrada);
            matriz[i][j] = entrada;
        }
    }
    int playerX, playerY, count;
    playerY = 0;
    playerX = 0;
    char mark, valid;
    mark = matriz[0][0];
    valid  = '!';
    count = 0;
    while(playerY >= 0 && playerY < linha && playerX >= 0 && playerX < coluna && count <= linha * coluna){
        
        switch(mark){
            case '>':
                playerX++;
                if(matriz[playerY][playerX] != '.' && matriz[playerY][playerX] != '*')
                    mark = matriz[playerY][playerX];
                if(matriz[playerY][playerX] == '*')
                    valid ='*';
                break;
            case '<':
                playerX--;
                if(matriz[playerY][playerX] != '.' && matriz[playerY][playerX] !='*')
                    mark = matriz[playerY][playerX];
                if(matriz[playerY][playerX] =='*')
                    valid ='*';
                break;
            case '^':
                playerY--;
                if(matriz[playerY][playerX] != '.' && matriz[playerY][playerX] !='*')
                    mark = matriz[playerY][playerX];
                if(matriz[playerY][playerX] =='*')
                    valid ='*';
                break;
            case 'v':
                playerY++;
                if(matriz[playerY][playerX] != '.' && matriz[playerY][playerX] !='*')
                    mark = matriz[playerY][playerX];
                if(matriz[playerY][playerX] =='*')
                    valid ='*';
                break;

        }
        if(valid == '*')
            break;
        count++;
    }
    printf("%c\n", valid);
    return 0;
}
