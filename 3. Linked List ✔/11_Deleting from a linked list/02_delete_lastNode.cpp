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
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Function to delete the last node of a linked list
void delete_lastNode () {

    struct Node *p = first;
    struct Node *q = NULL;

    while (p->next != NULL) {
        q = p;
        p = p->next;
    }

    q->next = NULL;
    int x = p->data;
    delete p;

}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    delete_lastNode();

    display(first);


    return 0;
}
