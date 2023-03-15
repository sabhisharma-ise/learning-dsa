// Traverse through a Linked List in C
// Assume we have a linked list containing data as 8 3 7 12 9

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n) {

    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;   // Move 'last' on last node

    for (int i = 1; i < n; i++) {

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;   // Move pointer 'last' on last node
        
    }
}


// Traverse through a Linked List (Display the content of it)
void display (struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    display(first); // Calling the display function, passing the first/head of the linked list

    return 0;
}