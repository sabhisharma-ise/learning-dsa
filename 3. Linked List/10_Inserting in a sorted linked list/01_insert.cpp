// Inserting a key element (x) in a sorted linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = new Node;

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

// Function to insert in a sorted linked list
void insert_sorted (struct Node *p, int x) {
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = x;

    // check for empty linked list
    if (first == NULL) { first = t; }

    else {

        while (p && p->data < x) {

            q = p;
            p = p->next;
        }

        // if new node is to be inserted before first node
        if (p == first) {

            t->next = first;
            first = t;
        }

        else {

            t->next = q->next;
            q->next = t;
        }
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    insert_sorted(first, 12);

    display(first);

    return 0;
}