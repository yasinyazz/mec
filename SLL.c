#include <stdio.h>
#include <stdlib.h>

// Structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void insertNewNode(struct Node** head_ref, int new_data, int position) {
    // check if the linked list is empty
    if (*head_ref == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    // create a new node with the given data
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;

    // check if the position is valid
    if (position < 0) {
        printf("The position should be a positive integer.\n");
        free(new_node);
        return;
    }

    // if the position is 0, insert the new node at the beginning of the linked list
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    // find the node before the position
    struct Node* current = *head_ref;
    int i;
    for (i = 0; i < position - 1; i++) {
        if (current->next == NULL) {
            printf("The position is larger than the length of the linked list.\n");
            free(new_node);
            return;
        }
        current = current->next;
    }

    // insert the new node after the node before the position
    new_node->next = current->next;
    current->next = new_node;
}


// Function to delete a node with the given key from the linked list
void deleteNode(struct Node **head_ref, int key) {
    if (*head_ref == NULL) {
        return;
    }
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to search for a node with the given key in the linked list
void searchNode(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            printf("Element %d found in the linked list.\n", key);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the linked list.\n", key);
}

// Function to print the linked list
void printLinkedList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Test the linked list operations
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    
    printf("Linked list: ");
    printLinkedList(head);
    
    printf("Enter the position and data of the  new node: ");
   int pos, data;
   scanf("%d%d", &pos, &data);
   insertNewNode(&head, data, pos);

    printf("Linked list: ");
    printLinkedList(head);

    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);
    searchNode(head, key);
	
	printf("Enter the element to delete: ");
	scanf("%d", &key);
    deleteNode(&head, key);
    printf("Linked list after deletion of %d: ", key);
    printLinkedList(head);

    return 0;
}
