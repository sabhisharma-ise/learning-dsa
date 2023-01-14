// Recursively, Counting the number of nodes in a linked list 
// Or simply the length of the linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// Recursive function to count the number of nodes in a linked list
int countNode (struct Node *p) {
    if (p != NULL) {
        return countNode(p->next) + 1;
    }
    else {
        return 0;
    }
}

int main () {

    struct Node *first;
    first = new Node;

    printf("%d ", countNode(first));

    return 0;
}