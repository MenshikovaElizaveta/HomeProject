#include "stack.h"
#include <stdio.h>

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