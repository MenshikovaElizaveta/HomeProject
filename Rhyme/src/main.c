#include "list.h"
#include <stdio.h>
#include <stdlib.h>


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