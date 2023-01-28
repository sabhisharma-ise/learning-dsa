// Iteratively, Counting the number of nodes in a linked list 
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

// Function to count the number of nodes in a linked list
int countNode (struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p=p->next;
    }
    return count;
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    int count = countNode(first);
    printf("%d", count);

    return 0;
}