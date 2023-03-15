// Program to delete from a doubly linked list

#include <iostream>
using namespace std;

// Structure for a doubly linked list
struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create (int A[], int n) {
    
    struct Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;

    for (int i = 1; i < n; i++) {

        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Display Function
void display (struct Node *p) {

    while (p) {

        printf("%d ", p->data);
        p = p->next;
    }
}

// Count Function
int length (struct Node *p) {

    int l = 0;
    while (p) {
        
        l++;
        p = p->next;
    }

    return l;
}

int Delete (struct Node *p, int pos) {

    int x = -1;
    p = first;

    // Invalid Conditions
    if (pos <= 0 || pos > length(first)) return -1;

    // Deleting first node
    if (pos == 1) {

        first = first->next;
        x = p->data;
        delete p;
        if (first) {
            first->prev = NULL;
        }
    }

    // Deleting from any other given position
    else {

        p = first;
        for (int i = 0; i < (pos - 1); i++) {

            p = p->next;
        }

        p->prev->next = p->next;
        if (p->next) {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }

    return x;
}

int main () {

    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);

    Delete(first, 1);    

    display(first);

    return 0;
}