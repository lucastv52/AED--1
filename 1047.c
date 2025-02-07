//Lucas Tosetti de Vasconcellos Ra 176577

#include <stdio.h>


int main(){
    int hi, mi, hf, mf, di, df, dt, dh, dm;
    scanf("%d %d %d %d", &hi, &mi, &hf, &mf);

    di = hi *60 + mi;
    df = hf * 60 + mf;

    if(df <= di) df += 24*60;

    dt = df - di;
    dh = dt/60;
    dm = dt % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dh, dm);

    return 0;
}
