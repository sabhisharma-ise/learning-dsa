// Iteratively, Counting the number of nodes in a linked list 
// Or simply the length of the linked list

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

// Function to count the number of nodes in a linked list
int countNode (struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p=p->next;
    }
}

int main () {

    struct Node *first;
    first = new Node;

    printf("%d ", countNode(first));

    return 0;
}