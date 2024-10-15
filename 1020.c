/*Lucas Tosetti de Vasconcellos RA:176577*/

#include <stdio.h>
 
int main() {
    int dias, ano, mes, dias2;
    scanf("%i",&dias);
    ano = dias/365;
    mes = (dias%365)/30;
    dias2 = ((dias%365)%30);
    printf("%i ano(s)\n%i mes(es)\n%i dia(s)\n",ano,mes,dias2);

    return 0;
}
