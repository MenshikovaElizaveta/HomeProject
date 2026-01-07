#include "count.h"

int countZeroElements(int arr[], int size){
    int k = 0;

    for( int i = 0; i < size; i++){
        if( arr[i] == 0){
            k++;
        }
    }

    return k;
}