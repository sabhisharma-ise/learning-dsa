// Display the contents of a linked list recursively in C++

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
    last = first;   // Move 'last' on last node

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;   // Move pointer 'last' on last node
        
    }
}

// Displays the content of a linked list
void display(struct Node *p) {
    if (p != NULL) {
        cout << p->data << " ";
        display(p->next);
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    display(first);

    return 0;
}