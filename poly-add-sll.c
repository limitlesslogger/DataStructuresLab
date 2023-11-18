#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node* next;
} nd;

typedef struct {
    nd* head;
} polynomial;

// Function to input terms into a polynomial
void input(polynomial* poly) {
    char ch = 'y';
    nd* new_node;

    while (ch == 'y') {
        new_node = (nd*)malloc(sizeof(nd));
        if (new_node == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        printf("Enter coefficient: ");
        scanf("%d", &new_node->coeff);
        printf("Enter exponent: ");
        scanf("%d", &new_node->exp);

        new_node->next = NULL;

        if (poly->head == NULL) {
            poly->head = new_node;
        } 
        else {
            nd* temp = poly->head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }

        printf("Insert more terms? (y/n): ");
        scanf(" %c", &ch);
    }
}

// Function to display a polynomial
void display(polynomial* poly) {
    if (poly->head == NULL) {
        printf("No terms\n");
    } 
    else {
        nd* temp = poly->head;
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;

        while (temp != NULL) {
            printf(" + %dx^%d", temp->coeff, temp->exp);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    // polynomial poly_A = {NULL};
    // polynomial poly_B = {NULL};
    polynomial poly_A;
    poly_A.head = NULL;

    polynomial poly_B;
    poly_B.head = NULL;

    printf("Input polynomial A:\n");
    input(&poly_A);
    printf("Polynomial A: ");
    display(&poly_A);

    printf("\nInput polynomial B:\n");
    input(&poly_B);
    printf("Polynomial B: ");
    display(&poly_B);

    return 0;
}
