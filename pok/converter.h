#ifndef CONVERTER_H
#define CONVERTER_H

int precedence(char op);
int isDigit(char ch);
int isOperator(char ch);
void infixToPostfix(char* infix, char* postfix);

#endif
