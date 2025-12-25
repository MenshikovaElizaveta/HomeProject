#include "list.h"
#include <stdio.h>
#include <stdlib.h>


Node* createNode(int val) {
    Node* new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("Ошибка выделения памяти!\n");
        return NULL;
    }
    new->num = val;
    new->next = NULL;
    return new;
}


void put(Node** head, int val) {
    Node* new = createNode(val);
    if (new == NULL) {
        return;
    }
    if (*head == NULL || (*head)->num >= val) {
        new->next = *head;
        *head = new;
        return;
    }
    Node* cur = *head;
    while (cur->next != NULL && cur->next->num < val) {
        cur = cur->next;
    }
    new->next = cur->next;
    cur->next = new;
}


void pop(Node** head, int val) {
    if (*head == NULL) {
        printf("Список пуст.\n");
        return;
    }
    if ((*head)->num == val) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* cur = *head;
    Node* previous = NULL;
    while (cur != NULL && cur->num != val) {
        previous = cur;
        cur = cur->next;
    }
    if (cur == NULL) {
        printf("Такого числа в списке нет.\n");
        return;
    }
    previous->next = cur->next;
    free(cur);
    return;
}


void printlist(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->num);
        cur = cur->next;
    }
}