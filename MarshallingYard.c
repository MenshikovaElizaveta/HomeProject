#include <string.h>
#include <stdio.h>

#define MaxSize 100

typedef struct {
    char data[MaxSize];
    int top;
} Stack;

void initStack(Stack* S) {
    S->top = -1;
}

int isEmpty(Stack* S) {
    return S->top == -1;
}

int isFull(Stack* S) {
    return S->top == MaxSize - 1;
}

void push(Stack* S, char val) {
    if (isFull(S)) {
        printf("Stack overflow!\n");
        return;
    }
    S->top++;
    S->data[S->top] = val;
}

char pop(Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty!\n");
        return '\0';
    }
    char val = S->data[S->top];
    S->top--;
    return val;
}

char peek(Stack* S) {
    if (isEmpty(S)) {
        printf("Stack is empty!\n");
        return '\0';
    }
    return S->data[S->top];
}

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
