// Linear Search in a linked list with iterative approach
// Given a Linked List and a key

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

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