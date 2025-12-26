#pragma once

int precedence(char op);
int isDigit(char ch);
int isOperator(char ch);
int infixToPostfix(char* infix, char* postfix);