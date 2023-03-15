// Recursively, Counting the number of nodes in a linked list 
// Or simply the length of the linked list

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

// Recursive function to count the number of nodes in a linked list
int RcountNode (struct Node *p) {
    if (p != NULL) {
        return RcountNode(p->next) + 1;
    }
    else {
        return 0;
    }
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    printf("Count is %d", RcountNode(first));

    return 0;
}