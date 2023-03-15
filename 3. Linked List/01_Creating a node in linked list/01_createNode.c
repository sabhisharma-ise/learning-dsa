// Creating a Node of a Linked List in C

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main () {

    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 10;
    p->next = 0;

    return 0;
}