#pragma once

#define MaxSize 100

typedef struct {
    char data[MaxSize];
    int top;
} Stack;

void initStack(Stack* S);
int isEmpty(Stack* S);
int isFull(Stack* S);
void push(Stack* S, char val);
char pop(Stack* S);
char peek(Stack* S);