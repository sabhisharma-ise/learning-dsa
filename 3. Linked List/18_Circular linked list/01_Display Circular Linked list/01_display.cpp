// Display Circular Linked List 

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head = NULL;

// Function to create a circular linked list by taking an array of elements
void create (int A[], int n) {

    struct Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;  // Circular
    last = head;

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Function to display a circular linked list
void display (struct Node *p) {
    // Use do-while loop for circular linked list
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
} 

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    display(head);

    return 0;
}