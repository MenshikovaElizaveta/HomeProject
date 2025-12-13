#include <stdio.h>


int main(void){
    int A, a, B, b, sign = 1, count=0;

    printf("Введите два числа: ");
    scanf("%d %d", &a, &b);

    if (b==0){
        printf("Ошибка: деление на ноль.\n");
        return 1;
    }
    
    if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
        sign = -1;
    }

    A = a;
    B = b;
    count = 0;

    if (A < 0){
        A = -A;
    }
    if (B < 0){
        B = -B;
    }

    while(A >= B){
        A = A - B;
        count++;
    }

    if (sign < 0 && A > 0){
        count++;
    }

    count *= sign;

    printf("%d неполное частноe от деления %d на %d", count, a, b);

    return 0;
}
