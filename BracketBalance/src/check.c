#include <string.h>

int checking(char* str, int len){
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (top == -1) { 
                return 1;
            }
            char open = stack[top--];
            if ((c      ==')'&&open!='(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return 1;
            }
        }
    }
    if (top != -1){
        return 1;
    }else{
        return 0;
    }
}