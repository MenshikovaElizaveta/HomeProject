#include "list.h"
#include "tests/test_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        if (!run_tests()) {
            printf("Тесты провалены\n");
            return 1;
        }
        return 0;
    }
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

   freeList(&head);

    return 0;
}