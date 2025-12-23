#include "converter.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

int main() {
    char infix[MaxSize];
    char postfix[MaxSize * 2];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0') {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}