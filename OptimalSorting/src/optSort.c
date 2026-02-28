#include "optSort.h"
#include <stdlib.h>


int* bubbleSort(int* numbers, int size){
    int* sortnumbers = calloc(size, sizeof(int));

    for (int i = 0; i < size; i++){
        sortnumbers[i] = numbers[i];
    }

    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (sortnumbers[j] > sortnumbers[j + 1]){
                int temp = sortnumbers[j + 1];
                sortnumbers[j + 1] = sortnumbers[j];
                sortnumbers[j] = temp;
            }
        }
    }

    return sortnumbers;
}