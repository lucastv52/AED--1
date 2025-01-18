#include <stdio.h>

int main(){
    int linha, coluna;
    scanf("%d %d", &coluna, &linha);
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
    while(playerY >= 0 && playerY < linha && playerX >= 0 && playerX < coluna && count <= linha * coluna && valid != '*'){        
        switch(mark){
            case '>':
                playerX++;               
                break;
            case '<':
                playerX--;                
                break;
            case '^':
                playerY--;
                break;
            case 'v':
                playerY++;                
                break;
        }
        if(matriz[playerY][playerX] != '.' && matriz[playerY][playerX] !='*')
            mark = matriz[playerY][playerX];
        else if(matriz[playerY][playerX] =='*')
            valid ='*';
        count++;
    }
    printf("%c\n", valid);
    return 0;
}
