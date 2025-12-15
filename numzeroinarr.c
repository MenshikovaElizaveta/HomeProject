#include <stdio.h>


int countZeroElements(int arr[], int size){
    int k = 0;

    for( int i = 0; i < size; i++){
        if( arr[i] == 0){
            k++;
        }
    }

    return k;
}


int main(void){
    int size;
    printf("Введите длину массива: ");
    scanf("%d", &size);
    int arr[size];
    printf("Введите %d чисел:\n", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    printf("массив содержит %d нулевых элементов", countZeroElements(arr, size));
    
    return 0;
}
