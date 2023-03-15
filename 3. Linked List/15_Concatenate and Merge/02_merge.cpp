// Merging of 2 linked lists
// Merging is a process of combining 2 sorted linked lists into a single sorted list
// We require an extra third pointer (say third), along with first and second
// And for helping this pointer, we need one more pointer (say last)
// Make sure the two linked lists should be sorted

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Create first linked list
void create_first(int a[], int n) {

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

// Create second linked list
void create_second(int a[], int n) {

    struct Node *t, *last;
    second = new Node;
    second->data = a[0];
    second->next = NULL;
    last = second;

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

// Function to merge 2 linked lists
void merge (struct Node *p, struct Node *q) {
    struct Node *last;

    // Initial Step
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }

    while (p && q) {
        // Repeating Step
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    // If any nodes are still present in any linked list
    if(p) last->next = p;
    if(q) last->next = q;
}



int main () {

    // Creating 2 linked lists
    int a[] = {2, 8, 10, 15};   // First sorted list
    create_first(a, 4);

    int b[] = {4, 7, 12, 14};   // Second sorted list
    create_second(b, 4);

    // Merging 2 linked list together
    merge(first, second);

    display (third);

    return 0;
}