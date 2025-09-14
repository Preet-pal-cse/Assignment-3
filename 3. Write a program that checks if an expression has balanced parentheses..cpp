#include <stdio.h>
#include <string.h>
#define MAX 100

int isBalanced(char expr[]) {
    char stack[MAX];
    int top = -1;
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') stack[++top] = '(';
        else if (expr[i] == ')') {
            if (top == -1) return 0;
            top--;
        }
    }
    return top == -1;
}
