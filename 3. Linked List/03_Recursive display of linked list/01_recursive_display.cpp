// Display the contents of a linked list recursively in C++

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// Displays the content of a linked list
void display(struct Node *p) {
    if (p != NULL) {
        cout << p->data << " ";
        display(p->next);
    }
}

int main () {

    struct Node *first;
    first = new Node;

    display(first);

    return 0;
}