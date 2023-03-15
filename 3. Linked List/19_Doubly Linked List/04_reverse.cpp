// Program to reverse a doubly linked list

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

void Reverse (struct Node *p) {

    struct Node *temp;

    while (p) {

        // Swap the links of a node
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        // Move p to next node
        p = p->prev; // Bcz, links are changed!

        // Check for last node & move first on it
        if (p != NULL && p->next == NULL) {
            first = p;
        }
    }
}

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    Reverse(first);

    display(first);

    return 0;
}