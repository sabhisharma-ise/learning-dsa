// Finding middle element of a linked list (singly)

// Method 2 (fidning mid in a single scan)
// We require 2 pointer (say 'p' and 'q')
// Say 'p' moves one node at a time (Slow Pointer)
// and 'q' moves two nodes at a time (Fast Pointer)
// So, by the time 'q' reaches the last node, 'p' will be in the middle (as the distance travelled by 'p' will be half of 'q')

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL;

void create(int a[], int n) {

    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
        
    }
}

void display (struct Node *p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int count (struct Node *p) {
    int c = 0;
    while (p) {
        c++;
        p = p->next;
    }
    return c;
}

// Finding mid node of a linked list using 2 pointer
void middle (struct Node *first) {

    struct Node *p = first;
    struct Node *q = first;

    while (q && q->next) {
        q = q->next->next;
        p = p->next;
    }

    printf("Middle node value: %d", p->data);
}

int main () {

    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);

    middle(first);

    // display (first);

    return 0;
}




