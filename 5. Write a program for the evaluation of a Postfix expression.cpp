#include <stdio.h>
#include <ctype.h>
#define MAX 100

int evalPostfix(char *exp) {
    int stack[MAX], top = -1;
    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i]))
            stack[++top] = exp[i] - '0';
        else {
            int val2 = stack[top--], val1 = stack[top--];
            switch (exp[i]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        }
    }
    return stack[top];
}
