// Insert

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

void insert (struct Node *p, int pos, int x) {

    struct Node *t;

    if (pos < 0 || pos > length(head)) return;

    if (pos == 0) {
        t = new Node;
        t->data = x;
        if (head == NULL) {
            head = t;
            head->next = head;
        } else {
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    } else {
        for (int i = 0; i < (pos - 1); i++) {
            p = p->next;
        }

        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }


}

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    insert(head, 3, 10);

    display(head);

    return 0;
}