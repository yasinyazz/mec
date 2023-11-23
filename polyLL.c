#include<stdio.h>
#include<stdlib.h>

// Node definition
typedef struct Node {
   int coef;
   int exp;
   struct Node* next;
} Node;

// Function prototypes
void addTerms(Node**, int, int);
void addPolynomials(Node* first, Node* second);
void printPolynomial(Node*);
void deletePolynomial(Node**);

// Main function
int main() {
   int val, choice, coef, exp;
   Node *first = NULL, *second = NULL;

   printf("Polynomial Operations: Addition and Display\n");
   do {
       printf("\nChoose operation:\n1. Add term to polynomial 1\n2. Add term to polynomial 2\n3. Add polynomials\n4. Display polynomials\n5. Exit\n");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
               printf("\nEnter coefficient and exponent: ");
               scanf("%d %d", &coef, &exp);
               addTerms(&first, coef, exp);
               break;

           case 2:
               printf("\nEnter coefficient and exponent: ");
               scanf("%d %d", &coef, &exp);
               addTerms(&second, coef, exp);
               break;

           case 3:
               addPolynomials(first, second);
               break;

           case 4:
               printf("\nPolynomial 1:\n");
               printPolynomial(first);
               printf("\nPolynomial 2:\n");
               printPolynomial(second);
               break;

           case 5:
               deletePolynomial(&first);
               deletePolynomial(&second);
               break;
       }
   } while (choice != 5);

   return 0;
}

// Function to add a new term to the polynomial
void addTerms(Node** poly_ref, int coef, int exp) {
   Node* new_node = (Node*) malloc(sizeof(Node));
   new_node->coef = coef;
   new_node->exp = exp;
   new_node->next = *poly_ref;
   *poly_ref = new_node;
}

// Function to add two polynomials
void addPolynomials(Node* first, Node* second) {
   Node* new_poly = NULL;

   while (first != NULL && second != NULL) {
       if (first->exp > second->exp) {
           addTerms(&new_poly, first->coef, first->exp);
           first = first->next;
       } else if (first->exp < second->exp) {
           addTerms(&new_poly, second->coef, second->exp);
           second = second->next;
       } else {
           int coef_sum = first->coef + second->coef;
           if (coef_sum != 0)
               addTerms(&new_poly, coef_sum, first->exp);
           first = first->next;
           second = second->next;
       }
   }

   while (first != NULL) {
       addTerms(&new_poly, first->coef, first->exp);
       first = first->next;
   }

   while (second != NULL) {
       addTerms(&new_poly, second->coef, second->exp);
       second = second->next;
   }

   printPolynomial(new_poly);
   deletePolynomial(&new_poly);
}

// Function to print the polynomial
void printPolynomial(Node* node) {
   while (node != NULL) {
       printf("%dx^%d ", node->coef, node->exp);
       node = node->next;
   }
   printf("\n");
}

// Function to delete the polynomial
void deletePolynomial(Node** poly_ref) {
   Node* current = *poly_ref;
   Node* next;

   while (current != NULL) {
       next = current->next;
       free(current);
       current = next;
   }

   *poly_ref = NULL;
}
