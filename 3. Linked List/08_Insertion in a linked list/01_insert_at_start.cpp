// Inserting before the first node in a linked list

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

// Function to insert at start of the linked list
void insert_start (int x) // x is data to be inserted in new node
{
    struct Node *t;
    t = new Node;   // Create a new node
    t->data = x;    // Insert the data in new node
    t->next = first; // Make the new node point to first node
    first = t; // Make the first pointer point to new node

}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    int x = 10;
    insert_start(x);

    display(first);

    return 0;
}