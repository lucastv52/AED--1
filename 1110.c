#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break; 

        int queue[100]; 
        int front = 0, rear = n - 1;

        for (int i = 0; i < n; i++) {
            queue[i] = i + 1;
        }

        printf("Discarded cards: ");
        int first = 1; 

        while (rear - front >= 1) { 
            if (!first) printf(", ");
            printf("%d", queue[front]);
            front = (front + 1) % 100; 
            first = 0;

            rear = (rear + 1) % 100;
            queue[rear] = queue[front];
            front = (front + 1) % 100; 
        }


        printf("\nRemaining card: %d\n", queue[front]);
    }

    return 0;
}
