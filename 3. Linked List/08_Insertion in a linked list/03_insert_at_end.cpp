// Inserting after the last node in a linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} * first = NULL;   // Initialize *first gloablly

void insert_end (int x);
{
    struct Node *t, *p;
    t = new Node;   // Create a new node
    t->data = x;    // Insert the data in new node
    p = first;
    while (p != NULL) {
        p = p->next;
    }
    t->next = NULL // Make the new node point to NULL
    p->next = t; // Make p's next point to new node

}

int main () {

    int x = 10;
    insert_end(x);
    // display(first);

}