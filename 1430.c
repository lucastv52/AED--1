#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char entrada[301];
    char *teste;

    while (1) {
        
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        
        if (strcmp(entrada, "*") == 0) break;

        int count = 0; 
        teste = strtok(entrada, "/"); 

        while (teste != NULL) {
            float time = 0;

            
            for (int i = 0; teste[i] != '\0'; i++) {
                switch (teste[i]) {
                    case 'W': time += 1; break;
                    case 'H': time += 0.5; break;
                    case 'Q': time += 0.25; break;
                    case 'E': time += 0.125; break;
                    case 'S': time += 0.0625; break;
                    case 'T': time += 0.03125; break;
                    case 'X': time += 0.015625; break;
                }
            }

            
            if (time == 1.0) {
                count++;
            }

            
            teste = strtok(NULL, "/");
        }

        
        printf("%d\n", count);
    }

    return 0;
}
