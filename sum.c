#include <stdio.h>
#include <string.h>

int main(){
    int set[]={918, 3, 7, 10, 99};
    int arr[sizeof(set)]={0};
    int k, b;
    for (int i = 0; i<sizeof(set); ++i){
        int a=set[i];
        int A= (a%10)+((a/10)%10)+((a/100)%10)+((a/1000)%10);
        arr[i]=A;
        
}
