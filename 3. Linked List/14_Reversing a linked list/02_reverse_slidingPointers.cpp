// Reversing the Links
// Reversing a linked list using sliding pointer
// Better Approach to reverse a linked list

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

// Function to reverse a linked list using sliding pointer (Reversing the links)
void reverse (struct Node *p) {
    p = first;
    struct Node *q = NULL;
    struct Node *r = NULL;
    while (p != NULL) {
        r = q;  // Bring r on q
        q = p;  // Bring q on p
        p = p->next;    // Move p to next node
        q->next = r;    // Link q to r(behind q)
    }
    first = q;  // Point first to q
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    reverse(first);

    display (first);

    return 0;
}
