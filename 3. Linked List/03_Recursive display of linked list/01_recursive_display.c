// Display the contents of a linked list recursively in C

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

// Displays the content of a linked list
void display(struct Node *p) {
    if (p != NULL) {
        printf("%d ", p->data); // Step 1
        display(p->next);   // Step 2
    }
}

int main () {

    struct Node *first;
    first = (struct Node *)malloc(sizeof(struct Node));

    display(first);

    return 0;
}