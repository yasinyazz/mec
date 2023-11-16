#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("the given node cannot be NULL");
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void printList(struct Node* n) {
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}

void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int main() {
    struct Node* head = NULL;
    int choice, data, pos;
    while (1) {
        printf("\n\n********** MENU **********\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after a node\n");
        printf("4. Print the list\n");
        printf("5. Free the list\n");
        printf("6. Exit\n");
        printf("**************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            struct Node* temp = head;
            printf("Enter the data after which a node is to be inserted: ");
            scanf("%d", &data);
            while (temp != NULL && temp->data != data) {
                temp = temp->next;
            }
            if (temp == NULL) {
                printf("The given node is not present in the list\n");
            } else {
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                insertAfter(temp, data);
            }
            break;
        case 4:
            printList(head);
            break;
        case 5:
            freeList(&head);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice. Please try again\n");
        }
    }
    return 0;
}
