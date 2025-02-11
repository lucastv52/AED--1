//Lucas Tosetti de Vasconcellos RA 176577

#include <stdio.h>
#include <string.h>

int main() {
    char palavra[51];

    while(scanf("%s", palavra) != EOF){       
        // Compara a entrada com os países e imprime a mensagem correspondente
        if (strcmp(palavra, "brasil") == 0)
            printf("Feliz Natal!\n");
        else if (strcmp(palavra, "alemanha") == 0)
            printf("Frohliche Weihnachten!\n");
        else if (strcmp(palavra, "austria") == 0)
            printf("Frohe Weihnacht!\n");
        else if (strcmp(palavra, "coreia") == 0)
            printf("Chuk Sung Tan!\n");
        else if (strcmp(palavra, "espanha") == 0)
            printf("Feliz Navidad!\n");
        else if (strcmp(palavra, "grecia") == 0)
            printf("Kala Christougena!\n");
        else if (strcmp(palavra, "estados-unidos") == 0)
            printf("Merry Christmas!\n");
        else if (strcmp(palavra, "inglaterra") == 0)
            printf("Merry Christmas!\n");
        else if (strcmp(palavra, "australia") == 0)
            printf("Merry Christmas!\n");
        else if (strcmp(palavra, "portugal") == 0)
            printf("Feliz Natal!\n");
        else if (strcmp(palavra, "suecia") == 0)
            printf("God Jul!\n");
        else if (strcmp(palavra, "turquia") == 0)
            printf("Mutlu Noeller\n");
        else if (strcmp(palavra, "argentina") == 0)
            printf("Feliz Navidad!\n");
        else if (strcmp(palavra, "chile") == 0)
            printf("Feliz Navidad!\n");
        else if (strcmp(palavra, "mexico") == 0)
            printf("Feliz Navidad!\n");
        else if (strcmp(palavra, "antardida") == 0)
            printf("Merry Christmas!\n");
        else if (strcmp(palavra, "canada") == 0)
            printf("Merry Christmas!\n");
        else if (strcmp(palavra, "irlanda") == 0)
            printf("Nollaig Shona Dhuit!\n");
        else if (strcmp(palavra, "belgica") == 0)
            printf("Zalig Kerstfeest!\n");
        else if (strcmp(palavra, "italia") == 0)
            printf("Buon Natale!\n");
        else if (strcmp(palavra, "libia") == 0)
            printf("Buon Natale!\n");
        else if (strcmp(palavra, "siria") == 0)
            printf("Milad Mubarak!\n");
        else if (strcmp(palavra, "marrocos") == 0)
            printf("Milad Mubarak!\n");
        else if (strcmp(palavra, "japao") == 0)
            printf("Merii Kurisumasu!\n");
        else
            printf("--- NOT FOUND ---\n");  // Mensagem para países não listados
    }
    return 0;
}
