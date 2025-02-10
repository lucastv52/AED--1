#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int time;  
    int index; 
    struct Node* next;
} Node;


Node* insert(Node* head, int time, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->time = time;
    newNode->index = index;
    newNode->next = NULL;

    if (!head || time < head->time || (time == head->time && index < head->index)) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next && (current->next->time < time || (current->next->time == time && current->next->index < index)))
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
    return head;
}


Node* pop_min(Node* head, int* time, int* index) {
    if (!head) return NULL;
    *time = head->time;
    *index = head->index;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


Node* update(Node* head, int index, int new_time) {
    return insert(head, new_time, index);
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int t[N];  
    for (int i = 0; i < N; i++)
        scanf("%d", &t[i]);

    Node* heap = NULL;
    for (int i = 0; i < N; i++)
        heap = insert(heap, 0, i);

    int max_time = 0;
    for (int i = 0; i < M; i++) {
        int client_time;
        scanf("%d", &client_time);

        int current_time, index;
        heap = pop_min(heap, &current_time, &index);
        int new_time = current_time + client_time * t[index];
        heap = update(heap, index, new_time);
        if (new_time > max_time)
            max_time = new_time;
    }

    printf("%d\n", max_time);
    return 0;
}
