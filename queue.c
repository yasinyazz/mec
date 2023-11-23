#include<stdio.h>
#include<stdlib.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue definition
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function prototypes
void enqueue(Queue*, int);
int dequeue(Queue*);
void printQueue(Queue*);

// Main function
int main() {
    int val, choice;
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = NULL;

    printf("Queue Operations: Enqueue, Dequeue and Display\n");
    do {
        printf("\nChoose operation:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to enqueue: ");
                scanf("%d", &val);
                enqueue(q, val);
                break;

            case 2:
                val = dequeue(q);
                if (val != -1)
                    printf("\nDequeued value: %d\n", val);
                else
                    printf("\nQueue is empty. Unable to dequeue.\n");
                break;

            case 3:
                printf("\nQueue contents:\n");
                printQueue(q);
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to add an element to the queue
void enqueue(Queue* q, int val) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = new_node;
    else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;

    Node* temp = q->front;
    int dequeued = temp->data;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return dequeued;
}

// Function to print the queue
void printQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
