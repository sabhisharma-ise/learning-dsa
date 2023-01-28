// Deleting the first node of a given linked list
// We'll simply move the 'first' to the next node
// And keep another pointer (say p) on the first node to keep track of it's address
// So we can delete it afterwards

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

// Function to delete the first node of a linked list
void delete_firstNode () {

    struct Node *p = first; // Extra pointer to store address of first node
    first = first->next;    // Move 'first' pointer to next node
    int x = p->data;    // Store data of first node if required
    delete p;   // Delete the first node
    // In C language
    // free(p);

}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    delete_firstNode();

    display(first);

    return 0;
}
