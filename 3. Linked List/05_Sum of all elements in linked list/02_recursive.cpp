// Recursively calculating the sum of all elements of a linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// Recursive function to calculate sum of all elements in linked list
int add (struct Node *p) {
    if (p != NULL) {
        return add(p->next) + p->data;
    }
    else {
        return 0;
    }
}

int main () {

    struct Node *first;
    first = new Node;

    printf("%d ", add(first));

    return 0;

}