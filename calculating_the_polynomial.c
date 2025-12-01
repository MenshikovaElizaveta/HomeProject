include <stdio.h>

int main(void){
    int x, X;
    printf("Введите число: ");
    scanf("%d", &x);
    X=x*x;
    printf("%d\n", (X+x)*(X+1)+1);
}
