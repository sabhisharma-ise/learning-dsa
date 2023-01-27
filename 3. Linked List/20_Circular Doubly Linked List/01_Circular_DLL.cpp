// Implementation of circular doubly linked list
// And creating the linked list using an array
// Also display and length function implementated

#include <iostream>
using namespace std;

// Structure for a circular doubly linked list
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;

void create (int A[], int n) {
    
    struct Node *t, *last;

    head = new Node;
    head->data = A[0];
    head->next = head->prev = head; // Circular
    last = head->prev;

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        head->prev = t;
        last = t;
    }
}

// Display Function
void display (struct Node *p) {

    do {

        printf("%d ", p->data);
        p = p->next;

    } while (p != head);

}

// Count Function
int length (struct Node *p) {

    int l = 0;
    do {
        
        l++;
        p = p->next;
    } while (p != head);

    return l;
}

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    printf("%d\n", length(head));

    display(head);

    return 0;
}