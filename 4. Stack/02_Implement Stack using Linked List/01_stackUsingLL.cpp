// Stack using Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

int isEmpty () {

    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int isFull () {

    struct Node *t = new Node;
    if (t == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Function to push a new node to the stack at the front
void push (int x) {

    struct Node *t;
    t = new Node;

    if (isFull()) printf("Stack Overflow\n");
    else {
        t->data =x;
        t->next = top;
        top = t;
    }
}

// Function to pop the top most element from the stack
int pop() {

    struct Node *t;
    int x = -1;

    if (isEmpty()) printf("Stack is Empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void display () {

    struct Node *p = top;
    while (p) {
        printf("%d ",p->data);
        p = p->next;
    }
}



int main () {

    push(10);
    push(20);
    push(30);

    display();

    printf("\n%d", pop());

    return 0;
}