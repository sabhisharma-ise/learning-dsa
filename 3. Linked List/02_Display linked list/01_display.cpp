// Traverse through a Linked List in C
// Assume we have a linked list containing data as 8 3 7 12 9

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// Traverse through a Linked List (Display the content of it)
void display (struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int main () {

    struct Node *first;
    first = new Node;

    display(first); // Calling the display function, passing the first/head of the linked list

    return 0;
}