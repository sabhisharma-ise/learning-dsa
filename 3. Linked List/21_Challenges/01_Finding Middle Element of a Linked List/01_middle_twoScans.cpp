// Finding middle element of a linked list (singly)

// Method 1
// Find the length
// Reach to mid node - for loop condition: i < (length / 2)

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

// Finding mid node of linked list using length function
void middle (struct Node *first) {

    struct Node *p = first;

    for (int i = 0; i < count(first)/2; i++) {
        p = p->next;
    }

    printf("Middle node value: %d", p->data);
}

// Here, for finding the mid node, we are first finding the length (one scan)
// And then doing another scan for traversing 'p' pointer to mid node
// We are doing 2 scans, let's do it in single scan in method 2

int main () {

    int a[] = {1, 2, 3, 4, 5, 6};
    create(a, 6);

    middle(first);

    // display (first);

    return 0;
}




