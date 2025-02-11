//Lucas Tosetti de Vasconcellos RA 176577

#include <stdio.h>


int menorNumeroOperacoes(int inicio, int destino, int numOperacoes) {
    int resultados[6], menor;

    
    if (inicio * 2 == destino || inicio * 3 == destino || inicio / 2 == destino || 
        inicio / 3 == destino || inicio + 7 == destino || inicio - 7 == destino || numOperacoes > 10) 
        return numOperacoes;

    
    resultados[0] = menorNumeroOperacoes(inicio * 2, destino, numOperacoes + 1);
    resultados[1] = menorNumeroOperacoes(inicio * 3, destino, numOperacoes + 1);
    resultados[2] = menorNumeroOperacoes(inicio / 2, destino, numOperacoes + 1);
    resultados[3] = menorNumeroOperacoes(inicio / 3, destino, numOperacoes + 1);
    resultados[4] = menorNumeroOperacoes(inicio + 7, destino, numOperacoes + 1);
    resultados[5] = menorNumeroOperacoes(inicio - 7, destino, numOperacoes + 1);

    
    menor = resultados[0];
    for (int i = 1; i < 6; i++) {
        if (resultados[i] < menor) menor = resultados[i];
    }

    return menor;
}

int main() {
    int inicio, destino;

    
    scanf("%d %d", &inicio, &destino);

    
    printf("%d\n", menorNumeroOperacoes(inicio, destino, 1));

    return 0;
}
