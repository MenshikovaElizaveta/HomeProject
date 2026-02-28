#include "optSort.h"
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int *numbers = calloc(100, sizeof(int));
    printf("введите числа через пробел:");
    int CountNum = 0;
    char usersym = 0;

    if (numbers == NULL) {
    printf("Ошибка выделения памяти!\n");
    return 1;
    }

    while (usersym != '\n'){
        if (scanf("%d", &numbers[CountNum]) == 1){
            CountNum++;
        }
        usersym = getchar();
    }

    printf("Числа в порядке возрастания: ");
    int *sortnumbers = bubbleSort(numbers, CountNum);

    if (sortnumbers == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    for (int i = 0; i < CountNum; i++) {
        printf("%d ", sortnumbers[i]);
    }

    printf("\n");
    free(numbers);
    free(sortnumbers);

    return 0;
}