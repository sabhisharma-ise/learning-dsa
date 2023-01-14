// Iteratively calculating the sum of all elements of a linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// Function to calculate sum of all elements in linked list
int add (struct Node *p) {
    int sum = 0;
    while (p) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int main () {

    struct Node *first;
    first = new Node;

    printf("%d ", add(first));

    return 0;
}