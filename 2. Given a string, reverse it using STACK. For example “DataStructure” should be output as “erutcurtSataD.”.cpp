#include <stdio.h>
#include <string.h>
#define MAX 100

void reverse(char str[]) {
    int stack[MAX], top = -1, len = strlen(str);
    for (int i = 0; i < len; i++)
        stack[++top] = str[i];
    for (int i = 0; i < len; i++)
        str[i] = stack[top--];
}

int main() {
    char s[] = "DataStructure";
    reverse(s);
    printf("%s\n", s); // Output: erutcurtSataD
    return 0;
}
