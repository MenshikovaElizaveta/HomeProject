#include <stdio.h>
#include <string.h>

int main(){
    char str[1000], stack[1000];
    int top = -1;
    printf("Enter the line: ");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) { 
                printf("the balance of the brackets is broken\n");
                return 0;
            }
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                printf("the balance of the brackets is broken\n");
                return 0;
            }
        }
    }
    if (top == -1)
        printf("the balance of the brackets is respected\n");
    else
        printf("the balance of the brackets is broken\n");
    return 0;
}
