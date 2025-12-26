#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool hasPair(int num, int arr[], int size) {
    int target = num + 1;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }

    return false;
}


int main(void){
    int *numbers = calloc(100, sizeof(int));
    printf("введите числа через пробел:");
    int CountNum = 0;

    if (numbers == NULL) {
    printf("Ошибка выделения памяти!\n");
    return 1;
    }

    while (scanf("%d", &numbers[CountNum]) == 1 && numbers[CountNum] != 0) {
        CountNum++;
    }

    printf("Числа у которых нет пар: ");

    for (int i = 0;  i < CountNum; i++){
        if(!hasPair(numbers[i], numbers, CountNum)){
            printf("%d ", numbers[i]);
        }
    }

    free(numbers);

    return 0;
}
