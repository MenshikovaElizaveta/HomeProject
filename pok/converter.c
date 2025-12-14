#include "converter.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0;
    int j = 0;
    Stack opStack;
    initStack(&opStack);

    while (infix[i] != '\0') {
        if (isDigit(infix[i])) {
            while (isDigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            push(&opStack, '(');
            i++;
        } else if (infix[i] == ')') {
            while (!isEmpty(&opStack) && peek(&opStack) != '(') {
                postfix[j++] = pop(&opStack);
                postfix[j++] = ' ';
            }
            pop(&opStack);
            i++;
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&opStack) &&
                   peek(&opStack) != '(' &&
                   precedence(infix[i]) <= precedence(peek(&opStack))) {
                postfix[j++] = pop(&opStack);
                postfix[j++] = ' ';
            }
            push(&opStack, infix[i]);
            i++;
        } else if (infix[i] == ' ') {
            i++;
        } else {
            printf("Invalid character: %c\n", infix[i]);
            postfix[0] = '\0';
            return;
        }
    }

    while (!isEmpty(&opStack)) {
        postfix[j++] = pop(&opStack);
        postfix[j++] = ' ';
    }

    if (j > 0 && postfix[j - 1] == ' ') {
        j--;
    }
    postfix[j] = '\0';
}
