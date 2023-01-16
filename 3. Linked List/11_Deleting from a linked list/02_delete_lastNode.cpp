// Deleting the last node of a given linked list
// We need 2 extra pointers (say p and q)
// Pointer 'q' to point at the previous node of last node
// Pointer 'p' to point to the last node

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void delete_lastNode () {

    struct Node *p = first;
    struct Node *q = NULL;

    while (p != NULL) {
        q = p;
        p = p->next;
    }

    q->next = NULL;
    int x = p->data;
    delete p;

}

int main () {

    


    return 0;
}
