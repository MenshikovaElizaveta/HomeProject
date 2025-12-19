#include <stdio.h>
#include <string.h>

int isLeftBracket(char c){
    return c == '(' || c == '[' || c == '{';
}

int isRightBracket(char c){
    return c == ')' || c == ']' || c == '}';
}

int Pair(char open, char c){
    return ((c == ')' && open == '(') || (c == ']' && open == '[') || (c == '}' && open == '{'));
}

int balance(char* str, int len){
    char stack[1000];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (isLeftBracket(str[i])) {
            stack[++top] = str[i];
        } 
        
        else if (isRightBracket(str[i])) {
            if (top == -1) { 
                return 0;
            }
            char open = stack[top--];
            if (!Pair(open, str[i])){
                return 0;
            }
        }
    }

    return (top == -1);
}


int main(){
    char str[1000];
    int len;

    printf("Enter the line: ");
    fgets(str, sizeof(str), stdin);
    len = strlen(str);

    if (balance(str, len)){
        printf("the balance of the brackets is respected\n");
    }

    else{
        printf("the balance of the brackets is broken\n");
    }

    return 0;
}
