// Inserting at given position (actually inserting after the pos) in a linked list

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

void insert_pos (int pos, int x)
{
    struct Node *t, *p; // Require two pointers in this case
    t = new Node;   // Create a new node
    t->data = x;    // Insert the data in new node
    p = first;  // Traverse p (pos - 1) steps
    for (int i = 0; i < (pos - 1) && (p != NULL); i++) {    // Also we should make sure if p != NULL while traversing
        p = p->next;
    }
    if (p != NULL) {
        t->next =  p->next;  // Make the new node point to p's next
        p->next = t;    // Make the p's next point to new node
    }

}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    int pos = 4;
    int x = 15;

    insert_pos(pos, x);
    display(first);

    return 0;
}