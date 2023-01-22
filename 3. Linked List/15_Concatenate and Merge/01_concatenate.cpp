// Let's concatenate 2 linked list 
// Concatenation means the joining of second list at the end of first list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;   // We'll create 2 linked lists & a pointer third for display the concatenated linked list

// Create first linked list
void create_first(int a[], int n) {

    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
        
    }
}

// Create second linked list
void create_second(int a[], int n) {

    struct Node *t, *last;
    second = new Node;
    second->data = a[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
        
    }
}

void display (struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function for concatenating 2 linked lists
void concatenate (struct Node *p, struct Node *q) {

    third = p;
    // Move 'p' on last node
    while(p->next != NULL) {
        p = p->next;
    }
    p->next = q;   // Concatenated
    q = NULL;  // Optional
}

int main () {

    // Creating 2 linked lists
    int a[] = {2, 9, 6, 8};
    create_first(a, 4);

    int b[] = {10, 4, 7};
    create_second(b, 3);

    // Joining 2 linked list together
    concatenate(first, second);

    display (third);

    return 0;
}