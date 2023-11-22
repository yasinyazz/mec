#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node* next;
};

// A queue has a front and a rear
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// To create a new queue, we need to initialize the front and rear as NULL
struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to add an element to the queue using enqueue operation
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to remove an element from the queue using dequeue operation
int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    if (queue->front == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);

    while (!isEmpty(queue)) {
        printf("%d\n", dequeue(queue));
    }

    return 0;
}
