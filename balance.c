#include <stdio.h>
#include <string.h>

int main(void){
    char str[100];
    int counter = 0;
    int len;

    printf("Enter the line: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    len = strlen(str);

    for(int i = 0; i < len; ++i){
        if (str[i] == '('){
            ++counter;
        }
        if (str[i] == ')'){
            --counter;
            if (counter < 0){
                break;
            }
        }
    }
    
    if (counter == 0){
        printf("Everything is just great\n");
    }
    else {
        printf("The balance of the brackets is broken\n");
    }

    return 0;
}
