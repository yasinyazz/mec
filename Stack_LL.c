#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if(top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node* temp = top;
    int poppedData = temp->data;
    top = temp->next;
    free(temp);
    return poppedData;
}

int peek() {
    if(top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

int isEmpty() {
    return top == NULL;
}

void printStack() {
    struct Node* temp = top;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    printStack();
    printf("Peeked element: %d\n", peek());
    printf("Popped element: %d\n", pop());
    printStack();
    return 0;
}