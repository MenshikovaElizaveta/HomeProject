#include <stdio.h>

int check(int []);

int main(){
    int set[]={1, 7, 10, 3};
    int i;
    for(i=0; i<sizeof(set); ++i){
        int k=0;
        int B[100];
        int a = set[i];
        while(a != 0){
            B[k]=(a%2);
            ++k;
            a=a/2;
        }
        if (check(B)==0){
            printf("%d\n", set[i]);
        }
    }
}

int check(int B[]){
    int l=0, r=sizeof(B)-1;
    while(l<r){
        if (B[l]==B[r]){
            ++l;
            --r;
        }
        else return 1;
    return 0;
    }
}
