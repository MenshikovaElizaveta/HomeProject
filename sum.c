#include <stdio.h>
#include <string.h>

int main(){
    int set[]={1, 3, 7, 10, 99};
    int k=0, b=0;
    for (int i = 0; i<sizeof(set); ++i){
        int a=set[i];
        int A= (a%10)+((a/10)%10)+((a/100)%10)+((a/1000)%10);
        if (k>A){
            k=A;
            b=a;
        }
    }
   printf("%d %d\n", k, b);
}
