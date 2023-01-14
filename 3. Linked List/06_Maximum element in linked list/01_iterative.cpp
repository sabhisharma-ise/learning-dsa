// Iteratively finding the maximum element in a linked list
// Algorithm remains same as we use to find max ele in an array

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

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

    struct Node *first;
    first = new Node;

    printf("%d ", maxElement(first));

    return 0;
}