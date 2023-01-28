// To remove duplicates from a sorted linked list

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

// Function to remove the duplicates in a sorted linked list
void removeDuplicates(struct Node *p) {
    struct Node *q = p->next;
    while (q != NULL) {
        if (p->data != q->data) {
            p = q;
            q = q->next;
        }

        else {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main() {

    int a[] = {3, 3, 7, 7, 25, 32};
    create(a, 6);

    removeDuplicates(first);

    display(first);

    return 0;
}