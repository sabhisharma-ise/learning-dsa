// Inserting before the first node in a linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} * first = NULL;   // Initialize *first gloablly

void insert_start (int x); // x is data to be inserted in new node
{
    struct Node *t;
    t = new Node;   // Create a new node
    t->data = x;    // Insert the data in new node
    t->next = first // Make the new node point to first node
    first = t; // Make the first pointer point to new node

}

int main () {

    int x = 10;
    insert_start(x);
    // display(first);

}