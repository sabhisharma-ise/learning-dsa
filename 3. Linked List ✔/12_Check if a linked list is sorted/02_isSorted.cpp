// Given a linked list of size n, you have to find whether the given linked list is sorted or not.
// The sorting can either be non-increasing or non-decreasing.

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

// Function to check if a linked list is sorted (either be non-increasing or non-decreasing)
bool isSorted (struct Node *first) {
    
    struct Node *p = first;
    struct Node *q = NULL;
    
    if (p->next == NULL) return true;

    q = p;
    p = p->next;

    // Check for ascending order
    int temp_a = 1; // assume ascending
    while (p) {

        if (p->data < q->data) {
            temp_a = 0;
            break;
        }

        q = p;
        p = p->next;
    }

    // Move p and q to their initial positions
    p = first;
    q = p;
    p = p->next;

    // Check for descending order
    int temp_b = 1; // assume descending
    while (p) {

        if (p->data > q->data) {
            temp_b = 0;
            break;
        }

        q = p;
        p = p->next;
    }

    return (temp_a | temp_b);

}

int main () {

    int a[] = {10, 5, 3};
    create(a, sizeof(a)/sizeof(a[0]));

    cout << isSorted(first);

    // display (first);

    return 0;
}