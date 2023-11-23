#include <stdio.h>
#include <stdlib.h>

int top = -1;
int stack[100];

void push(int value) {
    if (top >= 100 - 1) {
        printf("Stack is full.\n");
    } else {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top < 0) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        int popped_value = stack[top];
        top--;
        return popped_value;
    }
}

int peek() {
    if (top < 0) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    int value, choice;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                value = peek();
                if (value != -1) {
                    printf("Peeked value: %d\n", value);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
