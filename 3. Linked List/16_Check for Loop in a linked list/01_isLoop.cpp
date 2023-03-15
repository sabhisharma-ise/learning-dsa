// To check if a linked list contains a Loop or not
// We use two pointers for (say p and q)
// 'p' moves at 1x speed (slow pointer), 'q' moves at 2x speed (fast pointer)
// This algorithm is called Floyd's Cycle Finding Algorithm
// If the two pointers meet, then there is a Loop
// If they don't meet, then the linked list is Linear

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

int isLoop (struct Node *f) {
    struct Node *p, *q = f;
    while (p && q && q->next) {
        p = p->next;
        q = q->next->next;
        if (p == q) return 1;
    }
    return 0;
}

int main () {

    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);

    // Let's create a Loop in the linked list (i.e. point the last node to some node)
    struct Node *t1, *t2;
    t1 = first->next->next; // 30's address
    t2 = first->next->next->next->next; // 50's address
    t2->next = t1;  // last node points to third node, hence creating a loop

    int res = isLoop (first);
    if (res == 1) cout << "Loop Detected";
    else cout << "Loop Not Detected";

    // display (first);

    return 0;
}