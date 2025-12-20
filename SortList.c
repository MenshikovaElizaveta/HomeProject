#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *list = calloc(100, sizeof(int));
    int size = 0;
    char opcode;

    if (list == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }
    
    printf("Введите одну из следующих операций:\n");
    printf("0 - выйти\n");
    printf("1 - добавить значение в сортированный список\n");
    printf("2 - удалить значение из списка\n");
    printf("3 - распечатать список\n");
    
    opcode = getchar();
    
    while (opcode != '0') {
        if (opcode == '1') {
            printf("Добавьте число в список: ");
            scanf("%d", &list[size]);
            getchar();
            
            size++;
            int i = size - 1;
            
            while (i > 0 && list[i] < list[i - 1]) {
                int temp = list[i - 1];
                list[i - 1] = list[i];
                list[i] = temp;
                i--;
            }
            
            i = size - 1;
            printf("Введите следующую команду: ");
            opcode = getchar();
        } 
        else if (opcode == '2') {
            int del;
            printf("Удалите число из списка: ");
            scanf("%d", &del);
            getchar();
            
            int num;
            int found = 0;

            for (int i = 0; i < size; i++) {
                if (list[i] == del) {
                    num = i;
                    found = 1;
                    break;
                }
            }
            
            if (found) {
                for (int i = num; i < size - 1; i++) {
                    list[i] = list[i + 1];
                }
                size--;
            } 
            else {
                printf("Такого числа в списке нет.");
            }

            printf("Введите следующую команду: ");
            opcode = getchar();
        } 
        else if (opcode == '3') {
            for (int i = 0; i < size; i++) {
                printf("%d ", list[i]);
            }
            printf("\n");
            printf("Введите следующую команду: ");
            opcode = getchar();
        } 
        else {
            printf("Такой команды нет.");
            printf("Введите следующую команду: ");
            opcode = getchar();
        }
    }

    free(list);
    return 0;
}