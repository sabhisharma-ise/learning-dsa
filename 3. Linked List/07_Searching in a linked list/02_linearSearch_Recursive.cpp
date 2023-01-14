// Linear Search in a linked list with recursive approach
// Given a Linked List and a key

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// linear search implementation using recursion
struct Node *search (struct Node *p, int key) {
    if (p == NULL) {
        return NULL;
    }
    if (key == p->data) {
        return p;
    }
    return search(p->next, key);
}

int main () {

    struct Node *first;
    first = new Node;

    struct Node *res;
    res = search(first, 12);
    if (res != NULL) {
        printf("Key is found %d ", res->data);
    } else {
        printf("Key not found");
    }

    return 0;
}