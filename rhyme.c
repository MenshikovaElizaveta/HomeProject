#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
} Node;

Node* createNode(int val)
{
    Node* new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    new->num = val;
    new->next = NULL;
    return new;
}

void put(Node** head, int val)
{
    Node* new = createNode(val);
    if (new == NULL) {
        return;
    }
    if (*head == NULL) {
        new->next = new;
        *head = new;
        return;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new;
        new->next = *head;
        return;
    }
}

void pop(Node** head, Node* toDelete)
{
    if (*head == NULL) {
        return;
    }
    Node* prev = *head;
    while (prev->next != toDelete) {
        prev = prev->next;
    }
    prev->next = toDelete->next;
    if (*head == toDelete) {
        *head = toDelete->next;
    }
    free(toDelete);
}

int main(void)
{
    Node* head = NULL;
    Node* temp;
    int m, n;
    printf("m: ");
    scanf("%d", &m);
    printf("\nn: ");
    scanf("%d", &n);

    for (int num = 1; num <= n; num++) {
        put(&head, num);
    }

    temp = head;

    for (int i = 1; i < n; i++) {
        for (int count = 1; count < m; count++) {
            temp = temp->next;
        }
        Node* nextNode = temp->next;
        pop(&head, temp);
        temp = nextNode;
    }

    printf("k: %d", head->num);
    free(head);
    return 0;
}