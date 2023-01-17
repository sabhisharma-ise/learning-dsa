// Let's say we always insert at the end and using this we create our linked list
// We keep a pointer 'last' which points to the last node of the linked list
// By using such pointer, we can insert at the end with O(1) time complexity

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node * next;
} * first = NULL;

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


void display(struct Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert_end (struct Node *last, int x)
{
    struct Node *t;
    t = new Node;
    t->data = x;
    
    // check if linked list is empty
    if (first == NULL) { first = last = t; }

    // if linked list is not empty
    else 
    {
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    struct Node *last = NULL;

    last = first;

    // condition here is important to check 
    while (last->next != NULL) {
        last = last->next;
    }

    insert_end(last, 10);

    display(first);

    return 0;
}

// Stack Over Flow:-
// The time complexity for the Inserting at the end depends if you have the location of the last node, 
// if you do, it would be O(1) other wise you will have to search through the linked list and the time 
// complexity would jump to O(n).
 