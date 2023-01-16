// Inserting at given position (actually inserting after the pos) in a linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} * first = NULL;   // Initialize *first gloablly

void insert_pos (int pos, int x);
{
    struct Node *t, *p; // Require two pointers in this case
    t = new Node;   // Create a new node
    t->data = x;    // Insert the data in new node
    p = first;  // Traverse p (pos - 1) steps
    for (int i = 0; i < (pos - 1) && (p != NULL); i++) {    // Also we should make sure if p != NULL while traversing
        p = p->next;
    }
    if (p != NULL) {
        t->next =  p->next  // Make the new node point to p's next
        p->next = t;    // Make the p's next point to new node
    }

}

int main () {

    int pos = 4;
    int x = 10;
    insert_pos(pos, x);
    // display(first);

}