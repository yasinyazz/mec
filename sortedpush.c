#include<stdio.h>
#include<stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function prototypes
void sortedInsert(Node**, int);
void push(Node**, int);
int pop(Node**);
void printStack(Node*);

// Main function
int main() {
    int val, choice;
    Node *top = NULL, *t = NULL;

    printf("Stack Operations: Push, Pop and Display\n");
    do {
        printf("\nChoose operation:\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to push: ");
                scanf("%d", &val);
                sortedInsert(&top, val);
                break;

            case 2:
                val = pop(&top);
                if (val != -1)
                    printf("\nPopped value: %d\n", val);
                else
                    printf("\nStack is empty. Unable to pop.\n");
                break;

            case 3:
                printf("\nStack contents:\n");
                printStack(top);
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to insert a new value in a sorted way into the stack
void sortedInsert(Node** top_ref, int new_val) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_val;

    if (*top_ref == NULL || (*top_ref)->data >= new_val) {
        new_node->next = *top_ref;
        *top_ref = new_node;
    } else {
        Node* current = *top_ref;
        while (current->next != NULL && current->next->data < new_val)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
    }
}

// Function to add an element to the stack
void push(Node** top_ref, int new_val) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_val;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
}

// Function to remove an element from the stack
int pop(Node** top_ref) {
    if (*top_ref == NULL)
        return -1;

    Node* temp = *top_ref;
    int popped = temp->data;
    *top_ref = temp->next;
    free(temp);

    return popped;
}

// Function to print the stack
void printStack(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
