#include <stdio.h>
#include <stdlib.h>


int main(void){
    int A, a, B, b, count=0;

    printf("Введите два числа: ");
    scanf("%d %d", &a, &b);

    if (b==0){
        printf("Ошибка: деление на ноль.\n");
        return 1;
    }
    A = abs(a);
    B = abs(b);

    while(A >= B){
        A = A - B;
        count++;
    }

    if (a * b < 0){
        count *= -1;
        if (A != 0){
            count--;
        }
    }

    printf("%d неполное частноe от деления %d на %d", count, a, b);

    return 0;
}