// Given a linked list of size n, you have to find whether the given linked list is sorted or not.
// The sorting can either be non-increasing or non-decreasing.

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

// Function to check if a linked list is sorted (either be non-increasing or non-decreasing)
bool isSorted (struct Node *head) {

    bool a=true,b=true;
    Node* curr=head;
    if(head->next==NULL)
    return true;
    head=head->next;
    while(head!=NULL){
        if(curr->data > head->data){
            a=false;
        }
        if(curr->data < head->data){
            b=false;
        }
        curr=head;
        head=head->next;
    }
    
    return (a|b);

}

int main () {

    int a[] = {10, 5, 3};
    create(a, sizeof(a)/sizeof(a[0]));

    cout << isSorted(first);

    // display (first);

    return 0;
}