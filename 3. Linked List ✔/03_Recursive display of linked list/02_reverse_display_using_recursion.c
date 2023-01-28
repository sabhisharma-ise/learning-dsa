// Display the contents of a linked list in Reverse Order, recursively in C

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

// Displays the content of a linked list
void Rdisplay(struct Node *p) {
    if (p != NULL) {
        Rdisplay(p->next);   // Step 1   
        printf("%d ", p->data); // Step 2
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    Rdisplay(first);

    return 0;
}