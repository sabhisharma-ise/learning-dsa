// Implementation of doubly linked list
// And creating the linked list using an array
// Also display and length function implementated

#include <iostream>
using namespace std;

// Structure for a doubly linked list
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create (int A[], int n) {
    
    struct Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Display Function
void display (struct Node *p) {

    while (p) {

        printf("%d ", p->data);
        p = p->next;
    }
}

// Count Function
int length (struct Node *p) {

    int l = 0;
    while (p) {
        
        l++;
        p = p->next;
    }

    return l;
}

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    printf("%d\n", length(first));

    display(first);

    return 0;
}