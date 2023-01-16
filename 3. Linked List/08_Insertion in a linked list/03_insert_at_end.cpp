// Inserting after the last node in a linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} * first = NULL;   // Initialize *first gloablly

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
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

void insert_end (int x)
{
    struct Node *t, *p;
    t = new Node;   // Create a new node
    t->data = x;    // Insert the data in new node
    t->next = NULL;
    if (first == NULL) {
        first = t;
    } else {
        p = first;
        while (p != NULL) {
            p = p->next;
        }
        // t->next = NULL; Make the new node point to NULL
        p->next = t; // Make p's next point to new node
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    int x = 12;
    insert_end(x);

    display(first);

    return 0;
}