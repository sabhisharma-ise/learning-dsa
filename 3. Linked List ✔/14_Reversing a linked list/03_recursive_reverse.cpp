// Recursively reversing a linked list using two pointers 

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n) {

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

void display (struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to reverse linked list using recursion
void reverse (struct Node *q, struct Node *p) {
    if (p != NULL) {
        reverse (p, p->next);   // Move q to p & p to next node
        p->next = q;
    }
    else {
        first = q;  // When p == NULL: Move first to q
    }

}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    reverse(NULL, first);

    display (first);

    return 0;
}