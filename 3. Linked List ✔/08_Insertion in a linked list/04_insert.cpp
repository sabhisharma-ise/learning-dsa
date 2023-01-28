// Insert at any position (including at start of linked link)

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} * first = NULL;

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

int count (struct Node *p) {

    int c = 0;
    while (p) {
        c++;
        p = p->next;
    }

    return c;
}

void display (struct Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void insert(struct Node *p, int pos, int x) {
    struct Node *t;

    if (pos < 0 || pos > count(p)) return;

    t = new Node;
    t->data = x;
    
    // Inserting before the first node (pos = 0)
    if (pos == 0) 
    {
        t->next = first;
        first = t;
    }

    // Inserting at any given position (pos > 0)
    else 
    {
        for (int i = 0; i < (pos - 1); i++) 
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

}

int main () {

    int a[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(a, 8);

    int pos = 3;
    int x = 15;

    insert(first, pos, x);

    // we can use insert function to create a linked list (example below)
    // insert(first, 0, 10);
    // insert(first, 1, 20);
    // insert(first, 2, 30);
    // insert(first, 0, 0);
    // insert(first, 2, 25);
    // insert(first, 5, 40);
    display(first);

}