// Deleting a node from given position (say pos)

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void delete_at_pos (int pos) {

    struct Node *p = first;
    struct Node *q = NULL;

    for (int i = 0; i < (pos - 1); i++) {
        q = p;
        p = p->next;
    }

    q->next = p->next;
    int x = p->data;
    delete p;
    
}

int main () {

    


    return 0;
}
