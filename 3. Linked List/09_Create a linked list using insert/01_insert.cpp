// We'll use the same function insert() to create a linked list
// Always make sure to pass the first index as 0 (as initially there are 0 nodes of linked list)

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} * first = NULL;

void display(struct Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count(struct Node *p) {
    int c = 0;
    while (p) {
        c++;
        p = p->next;
    }
    return c;
}

void insert(int pos, int x) {
    struct Node *t, *p;

    if (pos < 0 || pos > count(first)) return;

    t = new Node;
    t->data = x;

    if (pos == 0) {
        t->next = first;
        first = t;
    }
    else {
        p = first;
        for (int i = 0; i < (pos - 1); i++) {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}


int main () {

    // Taking index of linked list
    // starting from 1 

    insert(0, 10);  // first node - use index 0
    insert(1, 20);  // insert after first node
    insert(2, 30);  // insert after second node
    insert(0, 0);   // insert before first node
    insert(3, 25);  // insert after third node
    display(first);

    return 0;
}