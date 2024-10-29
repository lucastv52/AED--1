#include <stdio.h>

int soma_linha(int matriz[9][9], int linha){
    //percorre uma linha específica da matriz, e retorna sua soma
    int soma = 0;
    for(int i =0; i<9;i++){       
        soma += matriz[linha][i];
    }       
    return soma;
}
int soma_colunas(int matriz[9][9], int coluna){
    //percorre uma coluna específica da matriz, e retorna sua soma
    int soma = 0;
    for(int i=0; i<9;i++)       
        soma += matriz[i][coluna];   
    return soma;
}
int soma_quadros(int matriz[9][9], int quadroX, int quadroY) {
    //percorre um quadrante 3x3 específico da matriz, e retorna sua soma
    int soma = 0;
    for(int i = quadroX * 3; i < (quadroX + 1) * 3; i++) {
        for(int j = quadroY * 3; j < (quadroY + 1) * 3; j++) {
            soma += matriz[i][j];
        }
    }
    return soma;
}
int verificar(int matriz[9][9]){
    int correto = 1;
    while (correto != 0){
        for(int i= 0; i<9;i++){
            if(soma_linha(matriz,i)!=45)
                correto = 0;
        }
        for(int i =0; i<9;i++){
            if(soma_colunas(matriz,i)!=45)
                correto = 0;
        }
        for(int i =0; i<3;i++){
            for(int j =0; j<3;j++){
                if(soma_quadros(matriz,i,j)!=45){
                    correto = 0;
                }
            }
        }

        break;
    } 
    return correto;
}
int main(void){
    int k;
    scanf("%d",&k);
    int tabelas[k][9][9];
    for(int m = 0;m<k;m++ ){
        for(int i=0; i<9;i++){
            for(int j =0;j<9;j++){
                scanf("%d",&tabelas[m][i][j]);
            }
        }
    

    if(verificar(tabelas[m])==1){
        printf("Instancia %d\n",m+1);
        printf("SIM\n");
        printf("\n");
    }
    else{
        printf("Instancia %d\n",m+1);
        printf("NAO\n");
        printf("\n");
    }

    }

    
}
