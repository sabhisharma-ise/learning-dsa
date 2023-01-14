// Traverse through a Linked List in C
// Assume we have a linked list containing data as 8 3 7 12 9

#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

// Traverse through a Linked List (Display the content of it)
void display (struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main () {

    struct Node *first;
    first = (struct Node *)malloc(sizeof(struct Node));

    display(first); // Calling the display function, passing the first/head of the linked list

    return 0;
}