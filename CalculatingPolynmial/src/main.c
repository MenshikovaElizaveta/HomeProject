#include <stdio.h>

int main(void){
    int x, a;
    printf("Введите число: ");
    scanf("%d", &x);
    a=x*x;
    printf("%d\n", (a+x)*(a+1)+1);
}