#include <stdio.h>


int main(void){
    int A, a, B, b, count=0;
    printf("Введите два числа: ");
    scanf("%d %d", &a, &b);
    if (b==0){
        printf("Ошибка: деление на ноль.\n");
        return 1;
    }
    if (a>0 && b>0){
        A=a;
        B=b;
        count=0;
        while(A>=B){
            A=A-B;
            count+=1;
        }
    }
    if (a>0 && b<0){
        A=a;
        B=b*(-1);
        count=0;
        while(A>=B){
            A=A-B;
            count+=1;
        }
        count*=-1;
        if (A>0) count--;
    }
    if (a<0 && b<0){
        A=a*(-1);
        B=b*(-1);
        count=0;
        while(A>=B){
            A=A-B;
            count+=1;
        }
    }
    if (a<0 && b>0){
        A=a*(-1);
        B=b;
        count=0;
        while(A>=B){
            A=A-B;
            count+=1;
        }
        count*=-1;
        if (A>0) count--;
    }
    printf("%d неполное частноe от деления %d на %d", count, a, b);
}