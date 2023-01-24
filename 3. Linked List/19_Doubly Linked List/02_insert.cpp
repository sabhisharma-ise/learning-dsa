// Program to insert in a doubly linked list

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

void insert (struct Node *p, int pos, int x) {

    struct Node *t;

    // Invalid Conditions
    if (pos < 0 || pos > length(first)) return;

    // Inserting before first node
    if (pos == 0) {

        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }

    // Inserting at any other given position
    else {

        t = new Node;
        t->data = x;
        t->next = p->next;
        t->prev = p;
        if (p->next) {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    insert(first, 0, 1);    // Insert 1 before the first node

    display(first);

    return 0;
}