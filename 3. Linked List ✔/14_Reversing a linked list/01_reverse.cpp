// Reversing the Elements
// Reversing a linked list using an extra array

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

int count (struct Node *p) {
    int c = 0;
    while (p) {
        c++;
        p = p->next;
    }
    return c;
}

// Function to reverse the linked list using an array
void reverse (struct Node *p) {
    p = first;
    int n = count(first);
    int A[n];   // Create an extra array of size of linked list
    for (int i = 0; i < n && p != NULL; i++) {
        A[i] = p->data;
        p = p->next;
    }
    p = first;  // set p to first again

    for (int i = n - 1; i >= 0; i--) {
        p->data = A[i];
        p = p->next;
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    reverse(first);

    display (first);

    return 0;
}