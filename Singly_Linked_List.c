#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
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

void sortList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* index = NULL;

    if (*head_ref == NULL) {
        return;
    }

    if (current->next == NULL) {
        return;
    }

    for (; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                int temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

void searchElement(struct Node* head, int search_element) {
    struct Node* current = head;
    int position = 0;

    while (current != NULL) {
        position++;
        if (current->data == search_element) {
            printf("Element found at position %d\n", position);
            return;
        }
        current = current->next;
    }

    printf("Element not found in the linked list\n");
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

   append(&head, 20);
    append(&head, 4);
    append(&head, 32);
    append(&head, 56);
    append(&head, 16);
   
    
    printf("Original Linked list is: \n");
    printList(head);

    sortList(&head);

    printf("\nSorted Linked list is: \n");
    printList(head);
    
    int s;
    printf("\nEnter the element to search: ");
    scanf("%d", &s);
    printf("\nSearching for element %d in the sorted list: \n", s);
    searchElement(head, s);

    return 0;
}
