#include "list.h"
#include <stdio.h>
#include <stdlib.h>


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