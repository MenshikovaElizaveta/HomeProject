#include "check.h"
#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    
    printf("Enter the line: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    int len = strlen(str);
    int result = checking(str, len);
    
    if (result == 0) {
        printf("The balance of the brackets is respected\n");
    } else {
        printf("The balance of the brackets is broken\n");
    }
    
    return 0;
}