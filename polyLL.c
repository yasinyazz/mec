#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coef;
    int exp;
    struct node *next;
}Polynomial;

void addTerm(Polynomial **poly, int coef, int exp){
    Polynomial *newNode = (Polynomial*)malloc(sizeof(Polynomial));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    if(*poly == NULL){
        *poly = newNode;
    } else {
        Polynomial *last = *poly;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = newNode;
    }
}

Polynomial* addPolynomials(Polynomial *poly1, Polynomial *poly2){
    Polynomial *result = NULL;
    Polynomial *ptr1 = poly1;
    Polynomial *ptr2 = poly2;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->exp > ptr2->exp){
            addTerm(&result, ptr1->coef, ptr1->exp);
            ptr1 = ptr1->next;
        } else if(ptr1->exp < ptr2->exp){
            addTerm(&result, ptr2->coef, ptr2->exp);
            ptr2 = ptr2->next;
        } else {
            int sum = ptr1->coef + ptr2->coef;
            if(sum != 0){
                addTerm(&result, sum, ptr1->exp);
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    while(ptr1 != NULL){
        addTerm(&result, ptr1->coef, ptr1->exp);
        ptr1 = ptr1->next;
    }

    while(ptr2 != NULL){
        addTerm(&result, ptr2->coef, ptr2->exp);
        ptr2 = ptr2->next;
    }

    return result;
}

void printPolynomial(Polynomial *poly){
    Polynomial *ptr = poly;
    while(ptr != NULL){
        printf("%dx^%d", ptr->coef, ptr->exp);
        ptr = ptr->next;
        if(ptr != NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

int main(){
    Polynomial *poly1 = NULL;
    Polynomial *poly2 = NULL;

    addTerm(&poly1, 2, 3);
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 1, 0);

    addTerm(&poly2, 1, 3);
    addTerm(&poly2, 4, 1);
    addTerm(&poly2, 5, 0);

    printPolynomial(poly1);
    printPolynomial(poly2);

    Polynomial *result = addPolynomials(poly1, poly2);
    printPolynomial(result);

    return 0;
}