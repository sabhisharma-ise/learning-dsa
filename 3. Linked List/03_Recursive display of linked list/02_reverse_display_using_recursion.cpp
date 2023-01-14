// Display the contents of a linked list in Reverse Order, recursively in C++

#include <iostream>

struct Node {
    int data;
    struct Node *next;
};

// Displays the content of a linked list
void display(struct Node *p) {
    if (p != NULL) {
        display(p->next);   // Step 1   
        printf("%d ", p->data); // Step 2
    }
}

int main () {

    struct Node *first;
    first = new Node;

    display(first);

    return 0;
}