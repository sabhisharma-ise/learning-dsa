// Improving Searching in Linear Search 
// Using Move to Head technique
// Here, we move the node (for which the key matches) to the head
// We need two pointers p and q, where q follows p

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;    // Initializing first pointer, to use in functions

// Improved linear search implementation using move-to-head technique
struct Node * search (struct Node *p, int key) {
    struct Node *q = NULL;
    while (p) {
        if (key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;  // Bring q to p
        p = p->next;    // Take p to next node
    }
}

int main () {

    struct Node *res;
    res = search(first, 12);
    if (res != NULL) {
        printf("Key is found %d ", res->data);
    } else {
        printf("Key not found");
    }

    return 0;
}