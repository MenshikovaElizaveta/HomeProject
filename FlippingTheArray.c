#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int m, n, temp;
    scanf("%d %d", &m, &n);
    
    for(int i = 0; i < size/2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    
    for(int i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    
    for(int i = 0; i < m/2; i++) {
        temp = arr[n + i];
        arr[n + i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i < size - 1) printf(" ");
    }
    printf("\n");
}
