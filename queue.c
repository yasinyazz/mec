#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1, count = 0;

void insert() {
    int element;
    if(rear == SIZE-1) {
        printf("\nQueue is Full\n");
    } else {
        if(front == -1) {
            front = 0;
        }
        printf("\nEnter the element to be inserted: ");
        scanf("%d", &element);
        rear++;
        queue[rear] = element;
        count++;
        printf("\nElement Inserted\n");
    }
}

void delete() {
    if(front == -1) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nDeleted Element is: %d\n", queue[front]);
        front++;
        if(front > rear) {
            front = rear = -1;
        }
        count--;
    }
}

void display() {
    if(front == -1) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nFront->%d", queue[front]);
        for(int i = front + 1; i <= rear; i++) {
            printf("->%d", queue[i]);
        }
        printf("\nTotal Number of Elements: %d\n", count);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\nQueue Operations: ");
        printf("\n1. Insert \n2. Delete \n3. Display \n4. Exit \n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
