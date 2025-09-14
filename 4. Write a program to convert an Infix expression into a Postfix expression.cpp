#include <stdio.h>
#include <ctype.h>
#define MAX 100

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX]; int top = -1, k = 0;
    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];
        if (isalnum(ch)) postfix[k++] = ch;
        else if (ch == '(') stack[++top] = ch;
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--; // remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = stack[top--];
            stack[++top] = ch;
        }
    }
    while (top != -1) postfix[k++] = stack[top--];
    postfix[k] = '\0';
}
