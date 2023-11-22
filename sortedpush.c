#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top >= stack->capacity - 1) {
        printf("Stack is full. Cannot push %d to stack.\n", value);
        return;
    }

    stack->array[++stack->top] = value;

    int i = stack->top;
    while (i > 0 && stack->array[i] < stack->array[i - 1]) {
        int temp = stack->array[i];
        stack->array[i] = stack->array[i - 1];
        stack->array[i - 1] = temp;
        i--;
    }
}

int pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty. Cannot pop an element from stack.\n");
        return -1;
    }

    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty. Cannot peek an element from stack.\n");
        return -1;
    }

    return stack->array[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top < 0;
}

int isFull(Stack* stack) {
    return stack->top >= stack->capacity - 1;
}

void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

int main() {
    Stack* stack = createStack(5);

    push(stack, 5);
    push(stack, 30);
    push(stack, 1);

    printf("Popped value from stack is %d.\n", pop(stack));
    printf("Top element of stack is %d.\n", peek(stack));

    freeStack(stack);

    return 0;
}