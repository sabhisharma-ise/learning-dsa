// To check if a linked list is sorted or not

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

// Function to check whether a linked list is sorted or not
bool sortedOrNOt (struct Node *p) {

    int x = INT_MIN;
    while(p != NULL) {
        // if p's data is smaller than x then not sorted
        if (p->data < x) {
            return false;
        }

        // otherwise it is sorted and check for remaining items
        x = p->data;    // Assign x with p's data 
        p = p->next;    // Move p to next node
    }

    return true;
}

int main () {

    int a[] = {3, 5, 7, 10, 25, 32};
    create(a, 6);

    (sortedOrNOt(first) == true) ? printf("YES") : printf("No");

    return 0;
}