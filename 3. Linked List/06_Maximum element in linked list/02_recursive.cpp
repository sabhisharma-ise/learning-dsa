// Recursively finding the maximum element in a linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

int maxElement (struct Node *p) {
    int x = 0;
    if (p == 0) {
        return INT_MIN;
    }
    x = maxElement(p->next);
    return (x > p->data) ? x : p->data ;
}

int main () {

    struct Node *first;
    first = new Node;

    printf("%d ", maxElement(first));

    return 0;
}