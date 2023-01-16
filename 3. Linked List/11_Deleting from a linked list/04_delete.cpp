// Complete Function for deleting any node (including first & at any position)

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

int Delete (int pos) {

    struct Node *p, *q;

    // delete the first node
    if (pos == 1) {
        p = first;
        first = first -> next;
        int x = p->data;
        delete p;
        return x;
    }

    // at any given position other than first
    else {
        p = first;
        q = NULL;
        for (int i = 0; i < (pos - 1) && p; i++) {
            q = p;
            p = p->next;
        }

        if (p) {
            q->next = p->next;
            int x = p->data;
            delete p;
            return x;
        }
    }
}

int main () {

    


    return 0;
}
