// Creating a Node of a Linked List in C++

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

int main () {

    struct Node *p;
    p = new Node;   // It will create a node
    p->data = 10;
    p->next = 0;    // NULL

    return 0;
}