#include <stdio.h>
#include <string.h>

main(){
    char str[100];
    int k=0;
    printf("Enter the line: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for(int i=0; i < strlen(str); ++i){
        if (str[i]=='(')
            ++k;
        if (str[i]==')'){
            --k;
            if (k<0) goto TheEnd;
        }
    }
    if (k==0) printf("Everything is just great\n");
    else {
        TheEnd:
            printf("The balance of the brackets is broken\n");
    }
}
