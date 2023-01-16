// Inserting a key element (x) in a sorted linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = new Node;

void display (struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

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

    insert_sorted(first, 10);

    display(first);


    return 0;
}