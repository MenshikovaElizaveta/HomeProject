#include <stdio.h>


int big(int a, int b){
    int sum1 = 0;
    int temp1 = a;

    while (temp1 > 0) {
        sum1 += temp1 % 2;
        temp1 /= 2;
    }
    
    int sum2 = 0;
    int temp2 = b;

    while (temp2 > 0) {
        sum2 += temp2 % 2;
        temp2 /= 2;
    }
    
    if (sum1 > sum2) {
        return a;
    }
    else{
        return b;
    }
}


int main(void){
    printf("Тесты:\n\n");
    printf("big(1, 2) = %d (ждем 2)\n", big(1, 2));
    printf("big(7, 8) = %d (ждем 7)\n", big(7, 8));
    printf("big(1, 100) = %d (ждем 100)\n", big(1, 100));
    printf("big(123, 123) = %d (ждем 123)\n", big(123, 123));
    printf("big(21, 22) = %d (ждем 22)\n", big(21, 22));
    printf("big(787, 788) = %d (ждем 788)\n", big(787, 788));
    
    return 0;
}
