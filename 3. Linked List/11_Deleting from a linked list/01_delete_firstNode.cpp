// Deleting the first node of a given linked list
// We'll simply move the 'first' to the next node
// And keep another pointer (say p) on the first node to keep track of it's address
// So we can delete it afterwards

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void delete_firstNode () {

    struct Node *p = first; // Extra pointer to store address of first node
    first = first->next;    // Move 'first' pointer to next node
    int x = p->data;    // Store data of first node if required
    delete p;   // Delete the first node

}

int main () {

    


    return 0;
}
