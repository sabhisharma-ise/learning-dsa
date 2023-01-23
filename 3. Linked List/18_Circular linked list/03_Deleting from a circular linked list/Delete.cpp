// Delete

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head;

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

int length (struct Node *p) {
    int l = 0;
    do {
        l++;
        p = p->next;
    } while (p != head);
    return l;
}

int Delete (struct Node *p, int pos) {

    struct Node *q = NULL;

    int x = -1;

    if (pos <= 0 || pos > length(head)) return -1;

    if (pos == 1) {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = head->next;
        x = head->data;
        delete head;
        head = p->next;
    } else {
        for (int i = 0; i < (pos - 1); i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    Delete(head, 3);

    display(head);

    return 0;
}