// Finding the intersecting point of 2 linked list (singly)
// Say L1 = 8, 6, 3, 9, 10, 4, 2, 12
// And L2 = 20, 30, 40, 10, 4, 2, 12 (Intersection Point is 10)
// We have to reach to end of linked lists and Traverse Backwards until we reach the intersecting node
// But in singly linkes list, we cannot traverse backward. It is possible using Stack!
// Take pointer 'p' on L1 and push all the addresses of nodes in one stack
// Take pointer 'q' on L2 and push all the addresses of nodes in another stack
// Starting from the top of both the stacks, pop out stack content till the addresses are same (and keep the deleted address in a variable)
// If the stack address become different, the previous address stored was the intersecting point of the linked lists.

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;

void create_first(int a[], int n) {

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

void create_second(int a[], int n) {

    struct Node *t, *last;
    second = new Node;
    second->data = a[0];
    second->next = NULL;
    last = second;

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

// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
Node* intersectPoint(Node* headA, Node* headB)
{
    stack<Node*> stackA;
    stack<Node*> stackB;
    Node* intersectNode = NULL;
  
    while (headB != NULL) {
        stackB.push(headB);
        headB = headB->next;
    }
  
    while (headA != NULL) {
        stackA.push(headA);
        headA = headA->next;
    }
  
    if (!stackA.top()->data == stackB.top()->data) {
        return NULL;
    }
  
    while (!stackA.empty() && !stackB.empty()
           && stackA.top()->data == stackB.top()->data) {
        intersectNode = stackA.top();
        stackA.pop();
        stackB.pop();
    }
  
    return intersectNode;
}

int main () {

    int a[] = {8, 6, 3, 9, 10, 4, 2, 12};
    create_first(a, 8);

    int b[] = {20, 30, 40, 10, 4, 2, 12};
    create_second(b, 7);

    struct Node *x = intersectPoint(first, second);

    printf("%d", x->data);

    return 0;
}

