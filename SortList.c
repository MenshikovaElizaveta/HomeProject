#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int num;
    struct Node* next;
} Node;


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


int main(void) {
    Node* head = NULL;
    int opcode, val;
    
    printf("Введите одну из следующих операций:\n");
    printf("0 - выйти\n");
    printf("1 - добавить значение в сортированный список\n");
    printf("2 - удалить значение из списка\n");
    printf("3 - распечатать список\n");
    
    do {
        scanf("%d", &opcode);
        while (getchar() != '\n');
        switch (opcode) {
        case 0:
            break;
        case 1:
            printf("Добавьте число в список: ");
            scanf("%d", &val);
            while (getchar() != '\n');
            put(&head, val);
            break;
        case 2:
            printf("Удалите число из списка: ");
            scanf("%d", &val);
            while (getchar() != '\n');
            pop(&head, val);
            break;
        case 3:
            printlist(head);
            break;
        default:
            printf("Такой команды нет.\n");
            break;
        }
        printf("Введите следующую команду: ");
    } while (opcode != 0);
    
    Node* cur = head;
    Node* nextNode;
    while (cur != NULL) {
        nextNode = cur->next;
        free(cur);
        cur = nextNode;
    }
    head = NULL;
    
    return 0;
}