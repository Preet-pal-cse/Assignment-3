#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

// Push operation
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// isEmpty
int isEmpty() { return top == -1; }

// isFull
int isFull() { return top == MAX - 1; }

// Display
void display() {
    if (top == -1) {
        printf("Stack Empty\n");
    } else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

// Peek
int peek() {
    if (top == -1) {
        printf("Stack Empty\n");
        return -1;
    }
    return stack[top];
}
