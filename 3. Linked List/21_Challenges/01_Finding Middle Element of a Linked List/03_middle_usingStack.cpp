// Finding middle element of a linked list (singly)

// Method 3
// Take a pointer 'p' on first node & create a stack
// Put the address of each node in the stack while traversing 'p' through the linked list
// We can know the size of the stack, divide it by 2, and pop out the number of nodes from the top (half of the stack)
// Current top represents the middle node

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

void middle (struct Node *first) {

    struct Node *p = first;

    // Stack will contain nodes
    struct Node * s[count(first)];

    int top = -1;
    while (p->next) {
        
        top++;
        s[top] = p;
        p = p->next;
    }

    for (int i = top; i >= count(first)/2; i--) {

        top--;
    }


    printf("Middle node : %d", top+1);
}


int main () {

    int a[] = {1, 2, 3, 4, 5, 6};
    create(a, 6);

    middle(first);

    // display (first);

    return 0;
}




