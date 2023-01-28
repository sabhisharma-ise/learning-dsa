// Iteratively finding the maximum element in a linked list
// Algorithm remains same as we use to find max ele in an array

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

// Recursive function to calculate sum of all elements in linked list
int add (struct Node *p) {
    if (p != NULL) {
        return add(p->next) + p->data;
    }
    else {
        return 0;
    }
}

int maxElement (struct Node *p) {
    int max = INT_MIN;
    while (p) {
        if (p->data > max) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    printf("Max element is %d", maxElement(first));

    return 0;
}