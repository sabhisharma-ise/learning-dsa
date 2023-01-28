// Linear Search in a linked list with iterative approach
// Given a Linked List and a key

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

// linear search implementation
struct Node *search (struct Node *p, int key) {
    while(p) {
        if (key == p->data) {
            return p;   // returns address of that node
        }
        p=p->next;
    }
    return NULL;
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    struct Node *res;
    res = search(first, 10);
    if (res != NULL) {
        printf("Key is found %d ", res->data);
    } else {
        printf("Key not found");
    }

    return 0;
}